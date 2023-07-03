#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QThread"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	this->update_controls(true, off, off, off, ProcFsThread::led_mode_t::LED_MODE_MANUAL);

	qRegisterMetaType<ProcFsThread::led_mode_t>("led_mode_t");

	thread = new ProcFsThread(this);
	connect(thread, &ProcFsThread::signal_update_controls,
					this, &MainWindow::update_controls);
	connect(this, &MainWindow::signal_enqueue_command_send_leds_states,
					thread, &ProcFsThread::enqueue_command_send_leds_states);
	connect(this, &MainWindow::signal_enqueue_command_send_leds_mode,
					thread, &ProcFsThread::enqueue_command_send_leds_mode);
	thread->start();
}

MainWindow::~MainWindow()
{
	delete ui;
}

QString MainWindow::i2c_get_led_status(int value)
{
	switch (value)
	{
		case off:       return "  0%";
		case light_25:  return " 25%";
		case light_50:  return " 50%";
		case light_100: return "100%";
	}
	return "undef";
}

void MainWindow::on_slider_r_valueChanged(int value)
{
	if (!can_update_controls)
		return;

	ui->label_status_r->setText(i2c_get_led_status(value));
	if (thread != nullptr)
		emit signal_enqueue_command_send_leds_states(ui->slider_r->value(), ui->slider_g->value(),
				ui->slider_b->value());
}

void MainWindow::on_slider_g_valueChanged(int value)
{
	if (!can_update_controls)
		return;

	ui->label_status_g->setText(i2c_get_led_status(value));
	if (thread != nullptr)
		emit signal_enqueue_command_send_leds_states(ui->slider_r->value(), ui->slider_g->value(),
				ui->slider_b->value());
}

void MainWindow::on_slider_b_valueChanged(int value)
{
	if (!can_update_controls)
		return;

	ui->label_status_b->setText(i2c_get_led_status(value));
	if (thread != nullptr)
		emit signal_enqueue_command_send_leds_states(ui->slider_r->value(), ui->slider_g->value(),
				ui->slider_b->value());
}

void MainWindow::on_checkBox_auto_stateChanged(int)
{
	if (!can_update_controls)
		return;

	if (thread != nullptr)
		emit signal_enqueue_command_send_leds_mode(ui->checkBox_auto->isChecked() ?
				ProcFsThread::LED_MODE_AUTO : ProcFsThread::LED_MODE_MANUAL);
}

void MainWindow::on_pushButton_clicked()
{
	thread->Stop = true;
	close();
}

void MainWindow::update_controls(bool ok, int r, int g, int b, ProcFsThread::led_mode_t led_mode)
{
	can_update_controls = false;
	if (ok)
	{
		ui->slider_r->setValue(r);
		ui->slider_g->setValue(g);
		ui->slider_b->setValue(b);
		ui->label_status_r->setText(i2c_get_led_status(r));
		ui->label_status_g->setText(i2c_get_led_status(g));
		ui->label_status_b->setText(i2c_get_led_status(b));
		ui->checkBox_auto->setChecked((led_mode == ProcFsThread::led_mode_t::LED_MODE_AUTO) ? true : false);
		ui->label_error->setText("");
	}
	else
	{
		ui->label_error->setText("Can't read LED status from procfs.");
	}
	can_update_controls = true;
}

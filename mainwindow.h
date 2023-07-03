#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "procfs_thread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

private:
	Ui::MainWindow *ui;
	ProcFsThread *thread;
	bool can_update_controls = true;

	enum led_command_t { off, light_25, light_50, light_100 };

	QString i2c_get_led_status(int value);

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private slots:
	void on_slider_r_valueChanged(int value);
	void on_slider_g_valueChanged(int value);
	void on_slider_b_valueChanged(int value);
	void on_checkBox_auto_stateChanged(int state);

	void on_pushButton_clicked();

public slots:
	void update_controls(bool ok, int r, int g, int b, ProcFsThread::led_mode_t led_mode);

signals:
	void signal_enqueue_command_send_leds_states(int8_t r, int8_t g, int8_t b);
	void signal_enqueue_command_send_leds_mode(enum ProcFsThread::led_mode_t led_mode);
};
#endif // MAINWINDOW_H

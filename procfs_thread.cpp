#include <cstring>
#include <QDebug>
#include <QThread>
#include "parse_commands.h"
#include "procfs_thread.h"

ProcFsThread::ProcFsThread(QObject *parent, bool b) : QThread(parent), Stop(b) { }

void ProcFsThread::run()
{
	while (!Stop)
	{
		if (command == COMMAND_SEND_LEDS_STATES)
		{
			command_send_leds_states(send_led_r, send_led_g, send_led_b);
			command = COMMAND_NONE;
		}
		else if (command == COMMAND_SEND_LEDS_MODE)
		{
			command_send_leds_mode(send_led_mode);
			command = COMMAND_NONE;
		}
		else
		{
			read_from_proc();
		}

		msleep(30);
	}
}

bool ProcFsThread::read_from_proc()
{
	char data[256] = { 0 };
	FILE *f = fopen(PROCFS_DEVICE, "r");
	if (f == NULL)
	{
//		qInfo("Can't open device %s.\n", PROCFS_DEVICE);
		emit signal_update_controls(false, 0, 0, 0, ProcFsThread::led_mode_t::LED_MODE_AUTO);
		return false;
	}

	int count = 0;
	int received;
	while ((received = fgetc(f)) != EOF)
		data[count++] = (char)received;
	fclose(f);

	ParseCommands parse;
	char result[256] = { 0 };
	bool ok = false;
	if (parse.parse_line(data, result))
	{
		char *command = parse.words[0];
		if (parse.words_count > 0 && strlen(command) > 0 && strcmp("leds", command) == 0 && parse.parameters_count == 4)
		{
			int8_t led_r_ = parse.parameters[0];
			int8_t led_g_ = parse.parameters[1];
			int8_t led_b_ = parse.parameters[2];
			enum ProcFsThread::led_mode_t led_mode_ = (enum ProcFsThread::led_mode_t)parse.parameters[3];
			emit signal_update_controls(true, led_r_, led_g_, led_b_, led_mode_);
			ok = true;
		}
	}
	if (!ok)
	{
		emit signal_update_controls(false, 0, 0, 0, ProcFsThread::led_mode_t::LED_MODE_AUTO);
	}

	parse.free_memory();
	return true;
}

bool ProcFsThread::send_to_device(const char *device, char *send)
{
	FILE *f = fopen(device, "w");
	if (f == NULL)
	{
//		qInfo("Can't open device %s.\n", device);
		return false;
	}

	fprintf(f, "%s", send);
	fclose(f);
	return true;
}

void ProcFsThread::command_send_leds_states(int8_t r, int8_t g, int8_t b)
{
	char s[64];
	sprintf(s, "leds %d %d %d", r, g, b);
	send_to_device(PROCFS_DEVICE, s);
}

void ProcFsThread::command_send_leds_mode(enum led_mode_t led_mode)
{
	char s[64];
	sprintf(s, "leds_mode %d", (int)led_mode);
	send_to_device(PROCFS_DEVICE, s);
}

void ProcFsThread::enqueue_command_send_leds_states(int8_t r, int8_t g, int8_t b)
{
	send_led_r = r;
	send_led_g = g;
	send_led_b = b;
	command = COMMAND_SEND_LEDS_STATES;
}

void ProcFsThread::enqueue_command_send_leds_mode(enum led_mode_t led_mode)
{
	send_led_mode = led_mode;
	command = COMMAND_SEND_LEDS_MODE;
}

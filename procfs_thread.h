#ifndef THREAD_H
#define THREAD_H

#include <QThread>

class ProcFsThread : public QThread
{
	Q_OBJECT;

public:
	enum led_mode_t { LED_MODE_AUTO, LED_MODE_MANUAL };

private:
	const char *PROCFS_DEVICE = "/proc/led_demo";

	enum command_t { COMMAND_NONE, COMMAND_SEND_LEDS_STATES, COMMAND_SEND_LEDS_MODE };

	volatile enum command_t command = COMMAND_NONE;
	int8_t send_led_r;
	int8_t send_led_g;
	int8_t send_led_b;
	enum led_mode_t send_led_mode;

	void run() override;
	void command_send_leds_states(int8_t r, int8_t g, int8_t b);
	void command_send_leds_mode(enum led_mode_t led_mode);
	bool read_from_proc();
	bool send_to_device(const char *device, char *send);

public:
	explicit ProcFsThread(QObject *parent = 0, bool b = false);
	bool Stop;

public slots:
	void enqueue_command_send_leds_states(int8_t r, int8_t g, int8_t b);
	void enqueue_command_send_leds_mode(enum led_mode_t led_mode);

signals:
	void signal_update_controls(bool read_ok, int r, int g, int b, led_mode_t led_mode);
};

#endif // THREAD_H

#ifndef __hs8100__
#define __hs8100__

struct set_brightness_s
{
	int level;
};

struct set_icon_s
{
	int icon_nr;
	int on;
};

struct set_led_s
{
	int led_nr;
	int on;
};

struct set_light_s
{
	int onoff;
};

struct set_fan_s
{
	int speed;
};

/* time must be given as follows:
 * time[0] = mjd high
 * time[1] = mjd low
 * time[2] = hour
 * time[3] = min
 * time[4] = sec
 */
struct set_standby_s
{
	char time[5];
};

struct set_time_s
{
	char time[5];
};

/* this sets the mode temporarily (for one ioctl)
 * to the desired mode. currently the "normal" mode
 * is the compatible vfd mode
 */
struct set_mode_s
{
	int compat; /* 0 = compatibility mode to vfd driver; 1 = hs8100_fp mode */
};

#if defined MODEL_SPECIFIC
struct modelspecific_s
{
	char data[19];  // the bytes to send, and returned
};
#endif

struct hchs8100_ioctl_data
{
	union
	{
		struct set_icon_s icon;
		struct set_led_s led;
		struct set_brightness_s brightness;
		struct set_light_s light;
		struct set_mode_s mode;
		struct set_standby_s standby;
		struct set_time_s time;
		struct set_fan_s fan;
#if defined MODEL_SPECIFIC
		struct modelspecific_s modelspecific;
#endif
	} u;
};
#endif
// vim:ts=4

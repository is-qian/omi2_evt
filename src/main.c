#include <zephyr/kernel.h>
#include <zephyr/shell/shell.h>
#include "mic.h"
#include "spi_flash.h"
#include "sd.h"
static int init_module(void)
{
	int ret;
	ret = mic_init();
	if (ret < 0)
	{
		printk("Failed to initialize mic module (%d)\n", ret);
	}

	ret = flash_init();
	if (ret < 0)
	{
		printk("Failed to initialize flash module (%d)\n", ret);
	}

	ret = app_sd_init();
	if (ret < 0)
	{
		printk("Failed to initialize sd module (%d)\n", ret);
	}
	return 0;
}

int main(void)
{
	if (init_module() < 0)
	{
		return -1;
	}
	shell_execute_cmd(NULL, "sd mount");
	shell_execute_cmd(NULL, "ble on");
	shell_execute_cmd(NULL, "button check");
	printk("Starting omi2 EVT test...\n");
	return 0;
}

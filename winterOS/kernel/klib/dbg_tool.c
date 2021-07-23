// ----------------------------
// <dbg_tool.c>
//              Jack Zheng
//              3112490969@qq.com
// ----------------------------
#include "type.h"
#include "stdio.h"
#include "const.h"
#include "protect.h"
#include "string.h"
#include "fs.h"
#include "proc.h"
#include "tty.h"
#include "console.h"
#include "global.h"
#include "keyboard.h"
#include "proto.h"

PUBLIC int printk2(const char *fmt, ...)
{
        int _cnt;
        char buf[STR_DEFAULT_LEN];

        va_list arg = (va_list)((char *)(&fmt) + 4);
        _cnt = vsprintf(buf, fmt, arg);
        int i = 0;
        while (i != _cnt)
                out_char((TTY_FIRST + 2)->console, buf[i++]);

        return _cnt;
}

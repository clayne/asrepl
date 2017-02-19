#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "asrepl.h"
#include "asrepl_commands.h"

/* REPL Commands */
static void cmd_help(const void    *unused);
static void cmd_exit(const void    *unused);
static void cmd_version(const void *unused);
static void cmd_dump(const void    *pid);
struct {
    const char *command;
    const char *description;
    void (*fn)(const void *);
    _Bool       hidden;
} static const repl_commands[] = {
    {"regs",    "Dump registers.",           cmd_dump,    false},
    {"help",    "This help message.",        cmd_help,    false},
    {"h",       "This help message.",        cmd_help,    true},
    {"?",       "This help message.",        cmd_help,    true},
    {"wtf",     "This help message.",        cmd_help,    true},
    {"q",       "Exit",                      cmd_exit,    true},
    {"x",       "Exit",                      cmd_exit,    true},
    {"exit",    "Exit",                      cmd_exit,    false},
    {"quit",    "Exit",                      cmd_exit,    true},
    {"ver",     "About/Version information", cmd_version, false},
    {"version", "About/Version information", cmd_version, true},
    {"about",   "About/Version information", cmd_version, true},
};

static void cmd_help(const void *unused)
{
    int i;

    PRINT("Commands:");
    for (i=0; i<sizeof(repl_commands)/sizeof(repl_commands[0]); ++i)
      if (!repl_commands[i].hidden)
        PRINT("%8s: %s",repl_commands[i].command,repl_commands[i].description);
}

static void cmd_exit(const void *unused)
{
    exit(EXIT_SUCCESS);
}

static void cmd_version(const void *unused)
{
    printf("--> %s v%d.%d\n"
           "--> %s\n"
           "--> (c) %d, Matt Davis (enferex)\n",
           NAME, MAJOR, MINOR,
           LICENSE, YEAR);
}

static void cmd_dump(const void *pid_ptr)
{
    if (pid_ptr == NULL)
      return;

    asrepl_dump_registers(*(pid_t *)pid_ptr);
}

cmd_status_e asrepl_cmd_process(const char *data, pid_t pid)
{
    int i;

    for (i=0; i<sizeof(repl_commands)/sizeof(repl_commands[0]); ++i) {
        const char *cmd = repl_commands[i].command;
        if (strncmp(data, cmd, strlen(cmd)) == 0) {
            repl_commands[i].fn((const void *)&pid);
            return CMD_HANDLED;
        }
    }

    return CMD_NOT_A_COMMAND;
}

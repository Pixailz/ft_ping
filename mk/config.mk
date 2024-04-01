# BASE
TARGET				:= ft_ping
CC					:= gcc
VERSION				:= 1.2.4
AUTHOR				:= Pixailz
LDFLAGS				:= -lm
CFLAGS				:= -Wall -Wextra $(LDFLAGS)

# check if the makefile is called from another or directly called
ifeq ($(MAIN),1)
DO_PRINT_USAGE		:= 0
else
DO_PRINT_USAGE		:= 1
endif

MAIN				:= 1
export MAIN

## SOME DIRS
BIN_DIR				:= ./
SRC_DIR				:= src
LIB_DIR				:= lib
OBJ_DIR				:= obj
INC_DIR				:= inc
MK_DIR				:= mk

## LIB CONFIG
USE_LIBFT			:= 1
USE_MINI_LIBX		:= 0

# SPECIFY MAKEFILE FLAGS
# MAKEFLAGS			:= --jobs=$(shell nproc)	# number of jobs (not working with re)
# MAKEFLAGS			+= --output-sync=target		# sync output, avoid intermixed result
MAKEFLAGS			:= --no-print-directory

# BASH
SHELL				:= /usr/bin/bash			# set bash path
.SHELLFLAGS			:= -eu -o pipefail -c		# set bash strict mode

# Always use GNU Make.
ifeq ($(origin .RECIPEPREFIX), undefined)
  $(error This Make does not support .RECIPEPREFIX. Please use GNU Make 4.0 or later)
endif
## Use '>' to instead of tab.
.RECIPEPREFIX		= >

## DEBUG
DEBUG				?= 0
DEBUG_FD			?= 420
CFLAGS				+= \
	-DPWD='"$(PWD)"' \
	-DDEBUG=$(DEBUG) \
	-DDEBUG_FD=$(DEBUG_FD) \
	-DVERSION='"$(VERSION)"' \
	-DAUTHOR='"$(AUTHOR)"'

ifeq ($(shell [ -z $(DEBUG_MAKE) ] && printf 1 || printf 0),1)
DEBUG_MAKE			?= 0
endif

ifeq ($(DEBUG),0)
CFLAGS				+= -Werror
else
ifeq ($(shell [ $(DEBUG) -ge 1 ] && printf 1 || printf 0),1)
CFLAGS				+= -g3
endif
ifeq ($(shell [ $(DEBUG) -ge 2 ] && printf 1 || printf 0),1)
.SHELLFLAGS			+= -x
endif
endif

## PARSE_VARIABLE

ifeq ($(ANSI_NO_COLOR),1)
CFLAGS				+= -DANSI_NO_COLOR
endif

ifeq ($(ANSI_NO_MODIFIER),1)
CFLAGS				+= -DANSI_NO_MODIFIER
endif

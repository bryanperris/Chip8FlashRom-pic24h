/* File:   main.c
 * Author: Bryan
 * Created on January 21, 2016, 10:21 PM
 * Description: 
 */

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "glcd.h"
#include "font5x7.h"
#include <math.h>

//#define DEBUG_I2C
#define GLCD

#ifndef DEBUG
#define DEBUG
#endif

const char romFont[]={
0xf0,0x90,0x90,0x90,0xf0,0x20,0x60,0x20,0x20,0x70,0xf0,0x10,0xf0,0x80,0xf0,0xf0,0x10,0xf0,0x10,0xf0,0x90,0x90,0xf0,0x10,0x10,0xf0,0x80,0xf0,0x10,0xf0,0xf0,0x80,0xf0
,0x90,0xf0,0xf0,0x10,0x20,0x40,0x40,0xf0,0x90,0xf0,0x90,0xf0,0xf0,0x90,0xf0,0x10,0xf0,0xf0,0x90,0xf0,0x90,0x90,0xe0,0x90,0xe0,0x90,0xe0,0xf0,0x80,0x80,0x80,0xf0
,0xe0,0x90,0x90,0x90,0xe0,0xf0,0x80,0xf0,0x80,0xf0,0xf0,0x80,0xf0,0x80,0x80};
const int romFont_size=80;

const char romChip8[]={
0x00,0xe0,0xa2,0x48,0x60,0x00,0x61,0x1e,0x62,0x00,0xd2,0x02,0xd2,0x12,0x72,0x08,0x32,0x40,0x12,0x0a,0x60,0x00,0x61,0x3e,0x62,0x02,0xa2,0x4a,0xd0,0x2e,0xd1,0x2e,0x72
,0x0e,0xd0,0x2e,0xd1,0x2e,0xa2,0x58,0x60,0x0b,0x61,0x08,0xd0,0x1f,0x70,0x0a,0xa2,0x67,0xd0,0x1f,0x70,0x0a,0xa2,0x76,0xd0,0x1f,0x70,0x03,0xa2,0x85,0xd0,0x1f,0x70
,0x0a,0xa2,0x94,0xd0,0x1f,0x12,0x46,0xff,0xff,0xc0,0xc0,0xc0,0xc0,0xc0,0xc0,0xc0,0xc0,0xc0,0xc0,0xc0,0xc0,0xc0,0xc0,0xff,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80
,0x80,0x80,0x80,0x80,0x80,0xff,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0xff,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80
,0x80,0x80,0x80,0x80,0xff,0x81,0x81,0x81,0x81,0x81,0x81,0xff,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0xff,0x81,0x81,0x81,0x81,0x81,0x81,0xff,0x81,0x81,0x81,0x81,0x81
,0x81,0xff,0xff};
const int romChip8_size=164;

const char romSctest[]={
0x12,0x12,0x20,0x54,0x72,0x6f,0x6e,0x69,0x78,0x20,0x28,0x63,0x29,0x20,0x32,0x30,0x31,0x30,0x00,0xe0,0x3f,0x00,0x13,0xe2,0x3e,0x00,0x13,0xe2,0x3d,0x00,0x13,0xe2,0x3c
,0x00,0x13,0xe2,0x3b,0x00,0x13,0xe2,0x3a,0x00,0x13,0xe2,0x39,0x00,0x13,0xe2,0x38,0x00,0x13,0xe2,0x37,0x00,0x13,0xe2,0x36,0x00,0x13,0xe2,0x35,0x00,0x13,0xe2,0x34
,0x00,0x13,0xe2,0x33,0x00,0x13,0xe2,0x32,0x00,0x13,0xe2,0x31,0x00,0x13,0xe2,0x30,0x00,0x13,0xe2,0x60,0x00,0x61,0x01,0x62,0x02,0x63,0x03,0x64,0x04,0x65,0x05,0x66
,0x06,0x67,0x07,0x68,0x08,0x69,0x09,0x6a,0x0a,0x6b,0x0b,0x6c,0x0c,0x6d,0x0d,0x6e,0x0e,0x6f,0x0f,0xa4,0x78,0xff,0x65,0x3f,0x00,0x13,0xf8,0x3e,0x00,0x13,0xf8,0x3d
,0x00,0x13,0xf8,0x3c,0x00,0x13,0xf8,0x3b,0x00,0x13,0xf8,0x3a,0x00,0x13,0xf8,0x39,0x00,0x13,0xf8,0x38,0x00,0x13,0xf8,0x37,0x00,0x13,0xf8,0x36,0x00,0x13,0xf8,0x35
,0x00,0x13,0xf8,0x34,0x00,0x13,0xf8,0x33,0x00,0x13,0xf8,0x32,0x00,0x13,0xf8,0x31,0x00,0x13,0xf8,0x30,0x00,0x13,0xf8,0x60,0x00,0xf0,0x29,0xf0,0x65,0x40,0x00,0x14
,0x02,0xa4,0x52,0x6e,0x7b,0xfe,0x33,0xf2,0x65,0x30,0x01,0x13,0xc6,0x31,0x02,0x13,0xc6,0x32,0x03,0x13,0xc6,0x6e,0x02,0x6f,0x00,0x60,0xfe,0x61,0x01,0x80,0x14,0x3f
,0x00,0x14,0x0c,0x6e,0x03,0x30,0xff,0x14,0x0c,0x6e,0x04,0x80,0x14,0x3f,0x01,0x14,0x0c,0x6e,0x05,0x30,0x00,0x14,0x0c,0x60,0x01,0x6e,0x06,0x6f,0x00,0x80,0x15,0x3f
,0x01,0x14,0x0c,0x6e,0x07,0x30,0x00,0x14,0x0c,0x6e,0x08,0x80,0x15,0x3f,0x00,0x14,0x0c,0x6e,0x09,0x30,0xff,0x14,0x0c,0x60,0x01,0x6e,0x0a,0x6f,0x00,0x80,0x17,0x3f
,0x01,0x14,0x0c,0x6e,0x0b,0x30,0x00,0x14,0x0c,0x6e,0x0c,0x60,0x01,0x61,0x00,0x80,0x17,0x3f,0x00,0x14,0x0c,0x6e,0x0d,0x30,0xff,0x14,0x0c,0x60,0xff,0x6e,0x0e,0x6f
,0x00,0x80,0x06,0x3f,0x01,0x14,0x0c,0x6e,0x0f,0x30,0x7f,0x14,0x0c,0x60,0x40,0x6e,0x10,0x80,0x06,0x3f,0x00,0x14,0x0c,0x6e,0x11,0x30,0x20,0x14,0x0c,0x6e,0x12,0x6f
,0x01,0x80,0x0e,0x3f,0x00,0x14,0x0c,0x6e,0x13,0x30,0x40,0x14,0x0c,0x60,0xfa,0x6e,0x14,0x80,0x0e,0x3f,0x01,0x14,0x0c,0x6e,0x15,0x30,0xf4,0x14,0x0c,0x61,0x7b,0x6e
,0x16,0x80,0x13,0x30,0x8f,0x14,0x0c,0xa4,0x88,0xf7,0x65,0xf7,0x75,0xa4,0x78,0xf7,0x65,0xf7,0x85,0x6e,0x17,0x37,0x07,0x14,0x0c,0x36,0x06,0x14,0x0c,0x35,0x05,0x14
,0x0c,0x34,0x04,0x14,0x0c,0x33,0x03,0x14,0x0c,0x32,0x02,0x14,0x0c,0x31,0x01,0x14,0x0c,0x30,0x00,0x14,0x0c,0x6e,0x18,0xaf,0xfe,0x60,0x02,0x6f,0x00,0xf0,0x1e,0x3f
,0x01,0x14,0x0c,0x14,0x90,0x24,0x12,0x70,0x0a,0x62,0x0b,0xf2,0x29,0xd0,0x15,0x70,0x05,0x62,0x0c,0xf2,0x29,0xd0,0x15,0x72,0x01,0xf2,0x29,0x70,0x05,0xd0,0x15,0x14
,0x50,0x24,0x12,0x70,0x0a,0xa4,0x64,0xd0,0x15,0x70,0x06,0xa4,0x69,0xd0,0x15,0x70,0x06,0xa4,0x64,0xd0,0x15,0x14,0x50,0x24,0x12,0x70,0x0a,0xa4,0x5a,0xd0,0x15,0x14
,0x50,0x24,0x12,0x70,0x0a,0xa4,0x55,0xd0,0x15,0x14,0x50,0x24,0x12,0x24,0x32,0x14,0x50,0x60,0x00,0x61,0x00,0xa4,0x5f,0xd0,0x15,0x70,0x05,0xa4,0x6e,0xd0,0x15,0x70
,0x06,0xd0,0x15,0xa4,0x5a,0x70,0x06,0xd0,0x15,0xa4,0x6e,0x70,0x05,0xd0,0x15,0x00,0xee,0x84,0x00,0x74,0x0a,0x85,0x10,0xa4,0x52,0xfe,0x33,0xf2,0x65,0xf0,0x29,0xd4
,0x55,0x74,0x06,0xf1,0x29,0xd4,0x55,0x74,0x06,0xf2,0x29,0xd4,0x55,0x00,0xee,0x14,0x50,0x00,0x00,0x00,0x10,0x30,0x10,0x10,0x10,0xf0,0x90,0x90,0x90,0xf0,0xf0,0x80
,0xf0,0x80,0xf0,0xf8,0x20,0x20,0x20,0xf8,0x88,0xc8,0xa8,0x98,0x88,0xe0,0x90,0xe0,0x90,0x88,0x90,0xa0,0xc0,0xa0,0x90,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x60,0x00,0x61,0x00,0xf0,0x29,0xd0,0x15,0x70,0x05,0xa4,0x73,0xd0,0x15,0x14,0x50,0x00};
const int romSctest_size=673;

const char romMaze[]={
0xa2,0x1e,0xc2,0x01,0x32,0x01,0xa2,0x1a,0xd0,0x14,0x70,0x04,0x30,0x40,0x12,0x00,0x60,0x00,0x71,0x04,0x31,0x20,0x12,0x00,0x12,0x18,0x80,0x40,0x20,0x10,0x20,0x40,0x80
,0x10,0x00};
const int romMaze_size=35;

const char romPong[]={
0x6a,0x02,0x6b,0x0c,0x6c,0x3f,0x6d,0x0c,0xa2,0xea,0xda,0xb6,0xdc,0xd6,0x6e,0x00,0x22,0xd4,0x66,0x03,0x68,0x02,0x60,0x60,0xf0,0x15,0xf0,0x07,0x30,0x00,0x12,0x1a,0xc7
,0x17,0x77,0x08,0x69,0xff,0xa2,0xf0,0xd6,0x71,0xa2,0xea,0xda,0xb6,0xdc,0xd6,0x60,0x01,0xe0,0xa1,0x7b,0xfe,0x60,0x04,0xe0,0xa1,0x7b,0x02,0x60,0x1f,0x8b,0x02,0xda
,0xb6,0x60,0x0c,0xe0,0xa1,0x7d,0xfe,0x60,0x0d,0xe0,0xa1,0x7d,0x02,0x60,0x1f,0x8d,0x02,0xdc,0xd6,0xa2,0xf0,0xd6,0x71,0x86,0x84,0x87,0x94,0x60,0x3f,0x86,0x02,0x61
,0x1f,0x87,0x12,0x46,0x02,0x12,0x78,0x46,0x3f,0x12,0x82,0x47,0x1f,0x69,0xff,0x47,0x00,0x69,0x01,0xd6,0x71,0x12,0x2a,0x68,0x02,0x63,0x01,0x80,0x70,0x80,0xb5,0x12
,0x8a,0x68,0xfe,0x63,0x0a,0x80,0x70,0x80,0xd5,0x3f,0x01,0x12,0xa2,0x61,0x02,0x80,0x15,0x3f,0x01,0x12,0xba,0x80,0x15,0x3f,0x01,0x12,0xc8,0x80,0x15,0x3f,0x01,0x12
,0xc2,0x60,0x20,0xf0,0x18,0x22,0xd4,0x8e,0x34,0x22,0xd4,0x66,0x3e,0x33,0x01,0x66,0x03,0x68,0xfe,0x33,0x01,0x68,0x02,0x12,0x16,0x79,0xff,0x49,0xfe,0x69,0xff,0x12
,0xc8,0x79,0x01,0x49,0x02,0x69,0x01,0x60,0x04,0xf0,0x18,0x76,0x01,0x46,0x40,0x76,0xfe,0x12,0x6c,0xa2,0xf2,0xfe,0x33,0xf2,0x65,0xf1,0x29,0x64,0x14,0x65,0x00,0xd4
,0x55,0x74,0x15,0xf2,0x29,0xd4,0x55,0x00,0xee,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00};
const int romPong_size=247;

const char romSimple[]={
0x00,0xe0,0x22,0x14,0x22,0x1a,0x22,0x1a,0x22,0x20,0x22,0x1a,0x60,0x01,0xf0,0x15,0x22,0x42,0x12,0x06,0x63,0x20,0x64,0x19,0x00,0xee,0xa2,0x4a,0xd3,0x46,0x00,0xee,0x60
,0x08,0xe0,0x9e,0x12,0x28,0x74,0x01,0x60,0x02,0xe0,0x9e,0x12,0x30,0x74,0xff,0x60,0x04,0xe0,0x9e,0x12,0x38,0x73,0xff,0x60,0x06,0xe0,0x9e,0x12,0x40,0x73,0x01,0x00
,0xee,0xf0,0x07,0x30,0x00,0x12,0x42,0x00,0xee,0x3c,0x18,0xff,0x18,0x24,0xe7,0x7e,0xff,0x99,0xe7,0x3c,0x00};
const int romSimple_size=86;

const char romJXO[]={
0xa2,0x4c,0x65,0x30,0x66,0x04,0xd5,0x66,0xa2,0x40,0x22,0x12,0xa2,0x46,0x22,0x12,0x12,0x08,0x61,0x1e,0x62,0x0d,0xd1,0x25,0x63,0x0c,0xf3,0x15,0xf4,0x07,0x34,0x00,0x12
,0x1c,0x4f,0x01,0x12,0x2e,0xd1,0x25,0xc1,0x3f,0xc2,0x1f,0x12,0x16,0xd1,0x25,0x00,0xee,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x88
,0x50,0x20,0x50,0x88,0x00,0xf8,0x88,0x88,0x88,0xf8,0x00,0xfc,0xfc,0xfc,0xfc,0xfc,0xfc,0x00};
const int romJXO_size=83;

const char romSpace[]={
0x12,0x25,0x53,0x50,0x41,0x43,0x45,0x20,0x49,0x4e,0x56,0x41,0x44,0x45,0x52,0x53,0x20,0x30,0x2e,0x39,0x31,0x20,0x42,0x79,0x20,0x44,0x61,0x76,0x69,0x64,0x20,0x57,0x49
,0x4e,0x54,0x45,0x52,0x60,0x00,0x61,0x00,0x62,0x08,0xa3,0xdd,0xd0,0x18,0x71,0x08,0xf2,0x1e,0x31,0x20,0x12,0x2d,0x70,0x08,0x61,0x00,0x30,0x40,0x12,0x2d,0x69,0x05
,0x6c,0x15,0x6e,0x00,0x23,0x91,0x60,0x0a,0xf0,0x15,0xf0,0x07,0x30,0x00,0x12,0x4b,0x23,0x91,0x7e,0x01,0x12,0x45,0x66,0x00,0x68,0x1c,0x69,0x00,0x6a,0x04,0x6b,0x0a
,0x6c,0x04,0x6d,0x3c,0x6e,0x0f,0x00,0xe0,0x23,0x75,0x23,0x51,0xfd,0x15,0x60,0x04,0xe0,0x9e,0x12,0x7d,0x23,0x75,0x38,0x00,0x78,0xff,0x23,0x75,0x60,0x06,0xe0,0x9e
,0x12,0x8b,0x23,0x75,0x38,0x39,0x78,0x01,0x23,0x75,0x36,0x00,0x12,0x9f,0x60,0x05,0xe0,0x9e,0x12,0xe9,0x66,0x01,0x65,0x1b,0x84,0x80,0xa3,0xd9,0xd4,0x51,0xa3,0xd9
,0xd4,0x51,0x75,0xff,0x35,0xff,0x12,0xad,0x66,0x00,0x12,0xe9,0xd4,0x51,0x3f,0x01,0x12,0xe9,0xd4,0x51,0x66,0x00,0x83,0x40,0x73,0x03,0x83,0xb5,0x62,0xf8,0x83,0x22
,0x62,0x08,0x33,0x00,0x12,0xc9,0x23,0x7d,0x82,0x06,0x43,0x08,0x12,0xd3,0x33,0x10,0x12,0xd5,0x23,0x7d,0x82,0x06,0x33,0x18,0x12,0xdd,0x23,0x7d,0x82,0x06,0x43,0x20
,0x12,0xe7,0x33,0x28,0x12,0xe9,0x23,0x7d,0x3e,0x00,0x13,0x07,0x79,0x06,0x49,0x18,0x69,0x00,0x6a,0x04,0x6b,0x0a,0x6c,0x04,0x7d,0xf4,0x6e,0x0f,0x00,0xe0,0x23,0x51
,0x23,0x75,0xfd,0x15,0x12,0x6f,0xf7,0x07,0x37,0x00,0x12,0x6f,0xfd,0x15,0x23,0x51,0x8b,0xa4,0x3b,0x12,0x13,0x1b,0x7c,0x02,0x6a,0xfc,0x3b,0x02,0x13,0x23,0x7c,0x02
,0x6a,0x04,0x23,0x51,0x3c,0x18,0x12,0x6f,0x00,0xe0,0xa4,0xdd,0x60,0x14,0x61,0x08,0x62,0x0f,0xd0,0x1f,0x70,0x08,0xf2,0x1e,0x30,0x2c,0x13,0x33,0x60,0xff,0xf0,0x15
,0xf0,0x07,0x30,0x00,0x13,0x41,0xf0,0x0a,0x00,0xe0,0xa7,0x06,0xfe,0x65,0x12,0x25,0xa3,0xc1,0xf9,0x1e,0x61,0x08,0x23,0x69,0x81,0x06,0x23,0x69,0x81,0x06,0x23,0x69
,0x81,0x06,0x23,0x69,0x7b,0xd0,0x00,0xee,0x80,0xe0,0x80,0x12,0x30,0x00,0xdb,0xc6,0x7b,0x0c,0x00,0xee,0xa3,0xd9,0x60,0x1c,0xd8,0x04,0x00,0xee,0x23,0x51,0x8e,0x23
,0x23,0x51,0x60,0x05,0xf0,0x18,0xf0,0x15,0xf0,0x07,0x30,0x00,0x13,0x89,0x00,0xee,0x6a,0x00,0x8d,0xe0,0x6b,0x04,0xe9,0xa1,0x12,0x57,0xa6,0x0c,0xfd,0x1e,0xf0,0x65
,0x30,0xff,0x13,0xaf,0x6a,0x00,0x6b,0x04,0x6d,0x01,0x6e,0x01,0x13,0x97,0xa5,0x0a,0xf0,0x1e,0xdb,0xc6,0x7b,0x08,0x7d,0x01,0x7a,0x01,0x3a,0x07,0x13,0x97,0x00,0xee
,0x3c,0x7e,0xff,0xff,0x99,0x99,0x7e,0xff,0xff,0x24,0x24,0xe7,0x7e,0xff,0x3c,0x3c,0x7e,0xdb,0x81,0x42,0x3c,0x7e,0xff,0xdb,0x10,0x38,0x7c,0xfe,0x00,0x00,0x7f,0x00
,0x3f,0x00,0x7f,0x00,0x00,0x00,0x01,0x01,0x01,0x03,0x03,0x03,0x03,0x00,0x00,0x3f,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x3f,0x08,0x08,0xff,0x00,0x00,0xfe,0x00
,0xfc,0x00,0xfe,0x00,0x00,0x00,0x7e,0x42,0x42,0x62,0x62,0x62,0x62,0x00,0x00,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x7d,0x00,0x41
,0x7d,0x05,0x7d,0x7d,0x00,0x00,0xc2,0xc2,0xc6,0x44,0x6c,0x28,0x38,0x00,0x00,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0xf7,0x10,0x14
,0xf7,0xf7,0x04,0x04,0x00,0x00,0x7c,0x44,0xfe,0xc2,0xc2,0xc2,0xc2,0x00,0x00,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0xef,0x20,0x28
,0xe8,0xe8,0x2f,0x2f,0x00,0x00,0xf9,0x85,0xc5,0xc5,0xc5,0xc5,0xf9,0x00,0x00,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0xbe,0x00,0x20
,0x30,0x20,0xbe,0xbe,0x00,0x00,0xf7,0x04,0xe7,0x85,0x85,0x84,0xf4,0x00,0x00,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0x7f,0x00
,0x3f,0x00,0x7f,0x00,0x00,0x00,0xef,0x28,0xef,0x00,0xe0,0x60,0x6f,0x00,0x00,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0xfe,0x00
,0xfc,0x00,0xfe,0x00,0x00,0x00,0xc0,0x00,0xc0,0xc0,0xc0,0xc0,0xc0,0x00,0x00,0xfc,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0xfc,0x10,0x10,0xff,0xf9,0x81,0xb9,0x8b
,0x9a,0x9a,0xfa,0x00,0xfa,0x8a,0x9a,0x9a,0x9b,0x99,0xf8,0xe6,0x25,0x25,0xf4,0x34,0x34,0x34,0x00,0x17,0x14,0x34,0x37,0x36,0x26,0xc7,0xdf,0x50,0x50,0x5c,0xd8,0xd8
,0xdf,0x00,0xdf,0x11,0x1f,0x12,0x1b,0x19,0xd9,0x7c,0x44,0xfe,0x86,0x86,0x86,0xfc,0x84,0xfe,0x82,0x82,0xfe,0xfe,0x80,0xc0,0xc0,0xc0,0xfe,0xfc,0x82,0xc2,0xc2,0xc2
,0xfc,0xfe,0x80,0xf8,0xc0,0xc0,0xfe,0xfe,0x80,0xf0,0xc0,0xc0,0xc0,0xfe,0x80,0xbe,0x86,0x86,0xfe,0x86,0x86,0xfe,0x86,0x86,0x86,0x10,0x10,0x10,0x10,0x10,0x10,0x18
,0x18,0x18,0x48,0x48,0x78,0x9c,0x90,0xb0,0xc0,0xb0,0x9c,0x80,0x80,0xc0,0xc0,0xc0,0xfe,0xee,0x92,0x92,0x86,0x86,0x86,0xfe,0x82,0x86,0x86,0x86,0x86,0x7c,0x82,0x86
,0x86,0x86,0x7c,0xfe,0x82,0xfe,0xc0,0xc0,0xc0,0x7c,0x82,0xc2,0xca,0xc4,0x7a,0xfe,0x86,0xfe,0x90,0x9c,0x84,0xfe,0xc0,0xfe,0x02,0x02,0xfe,0xfe,0x10,0x30,0x30,0x30
,0x30,0x82,0x82,0xc2,0xc2,0xc2,0xfe,0x82,0x82,0x82,0xee,0x38,0x10,0x86,0x86,0x96,0x92,0x92,0xee,0x82,0x44,0x38,0x38,0x44,0x82,0x82,0x82,0xfe,0x30,0x30,0x30,0xfe
,0x02,0x1e,0xf0,0x80,0xfe,0x00,0x00,0x00,0x00,0x06,0x06,0x00,0x00,0x00,0x60,0x60,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x18,0x18,0x00,0x18,0x7c,0xc6,0x0c
,0x18,0x00,0x18,0x00,0x00,0xfe,0xfe,0x00,0x00,0xfe,0x82,0x86,0x86,0x86,0xfe,0x08,0x08,0x08,0x18,0x18,0x18,0xfe,0x02,0xfe,0xc0,0xc0,0xfe,0xfe,0x02,0x1e,0x06,0x06
,0xfe,0x84,0xc4,0xc4,0xfe,0x04,0x04,0xfe,0x80,0xfe,0x06,0x06,0xfe,0xc0,0xc0,0xc0,0xfe,0x82,0xfe,0xfe,0x02,0x02,0x06,0x06,0x06,0x7c,0x44,0xfe,0x86,0x86,0xfe,0xfe
,0x82,0xfe,0x06,0x06,0x06,0x44,0xfe,0x44,0x44,0xfe,0x44,0xa8,0xa8,0xa8,0xa8,0xa8,0xa8,0xa8,0x6c,0x5a,0x00,0x0c,0x18,0xa8,0x30,0x4e,0x7e,0x00,0x12,0x18,0x66,0x6c
,0xa8,0x5a,0x66,0x54,0x24,0x66,0x00,0x48,0x48,0x18,0x12,0xa8,0x06,0x90,0xa8,0x12,0x00,0x7e,0x30,0x12,0xa8,0x84,0x30,0x4e,0x72,0x18,0x66,0xa8,0xa8,0xa8,0xa8,0xa8
,0xa8,0x90,0x54,0x78,0xa8,0x48,0x78,0x6c,0x72,0xa8,0x12,0x18,0x6c,0x72,0x66,0x54,0x90,0xa8,0x72,0x2a,0x18,0xa8,0x30,0x4e,0x7e,0x00,0x12,0x18,0x66,0x6c,0xa8,0x72
,0x54,0xa8,0x5a,0x66,0x18,0x7e,0x18,0x4e,0x72,0xa8,0x72,0x2a,0x18,0x30,0x66,0xa8,0x30,0x4e,0x7e,0x00,0x6c,0x30,0x54,0x4e,0x9c,0xa8,0xa8,0xa8,0xa8,0xa8,0xa8,0xa8
,0x48,0x54,0x7e,0x18,0xa8,0x90,0x54,0x78,0x66,0xa8,0x6c,0x2a,0x30,0x5a,0xa8,0x84,0x30,0x72,0x2a,0xa8,0xd8,0xa8,0x00,0x4e,0x12,0xa8,0xe4,0xa2,0xa8,0x00,0x4e,0x12
,0xa8,0x6c,0x2a,0x54,0x54,0x72,0xa8,0x84,0x30,0x72,0x2a,0xa8,0xde,0x9c,0xa8,0x72,0x2a,0x18,0xa8,0x0c,0x54,0x48,0x5a,0x78,0x72,0x18,0x66,0xa8,0x66,0x18,0x5a,0x54
,0x66,0x72,0x6c,0xa8,0x72,0x2a,0x00,0x72,0xa8,0x72,0x2a,0x18,0xa8,0x30,0x4e,0x7e,0x00,0x12,0x18,0x66,0x6c,0xa8,0x00,0x66,0x18,0xa8,0x30,0x4e,0x0c,0x66,0x18,0x00
,0x6c,0x30,0x4e,0x24,0xa8,0x72,0x2a,0x18,0x30,0x66,0xa8,0x1e,0x54,0x66,0x0c,0x18,0x9c,0xa8,0x24,0x54,0x54,0x12,0xa8,0x42,0x78,0x0c,0x3c,0xa8,0xae,0xa8,0xa8,0xa8
,0xa8,0xa8,0xa8,0xa8,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
const int romSpace_size=1302;

const char romTrip8[]={
0x12,0x14,0x52,0x45,0x56,0x49,0x56,0x41,0x4c,0x53,0x54,0x55,0x44,0x49,0x4f,0x53,0x32,0x30,0x30,0x38,0x00,0xe0,0x6d,0x20,0xfd,0x15,0x23,0xbe,0x23,0xc6,0x6d,0x40,0xfd
,0x15,0x23,0xbe,0x23,0xc6,0x6d,0x20,0xfd,0x15,0x23,0xbe,0xa4,0x83,0x24,0x48,0x6d,0x80,0xfd,0x15,0x23,0xbe,0xa4,0x83,0x24,0x48,0xa5,0x83,0x24,0x48,0x6d,0x00,0x6b
,0x00,0x22,0xc6,0x4b,0x00,0x22,0xe4,0x4b,0x01,0x23,0x86,0x4b,0x02,0x22,0xec,0x4b,0x03,0x23,0x86,0x4b,0x04,0x22,0xf4,0x4b,0x05,0x23,0x86,0x60,0x01,0xf0,0x15,0x23
,0xbe,0x7d,0x01,0x60,0x3f,0x8c,0xd0,0x8c,0x02,0x4c,0x00,0x22,0x70,0x12,0x44,0x4b,0x00,0x22,0x90,0x4b,0x01,0x22,0xcc,0x4b,0x02,0x22,0xa2,0x4b,0x03,0x22,0xd4,0x4b
,0x04,0x22,0xb4,0x4b,0x05,0x22,0xdc,0x7b,0x01,0x4b,0x06,0x6b,0x00,0x00,0xee,0x23,0x08,0xc9,0x03,0x89,0x94,0x89,0x94,0x89,0x94,0x89,0x94,0x89,0x94,0x23,0x66,0x00
,0xee,0x22,0xfc,0xc9,0x03,0x89,0x94,0x89,0x94,0x89,0x94,0x89,0x94,0x89,0x94,0x23,0x66,0x00,0xee,0x23,0x18,0xc9,0x03,0x89,0x94,0x89,0x94,0x89,0x94,0x89,0x94,0x89
,0x94,0x23,0x66,0x00,0xee,0x6e,0x00,0x23,0x08,0x00,0xee,0x23,0x66,0x6e,0x00,0x22,0xfc,0x00,0xee,0x23,0x66,0x6e,0x00,0x23,0x18,0x00,0xee,0x23,0x66,0x6e,0x00,0x23
,0x08,0x00,0xee,0x23,0x08,0x7e,0x03,0x23,0x08,0x00,0xee,0x22,0xfc,0x7e,0x02,0x22,0xfc,0x00,0xee,0x23,0x18,0x7e,0x02,0x23,0x18,0x00,0xee,0x6c,0x00,0x23,0x3a,0x23
,0x3a,0x23,0x3a,0x23,0x3a,0x00,0xee,0x6c,0x00,0x23,0x24,0x23,0x24,0x23,0x24,0x23,0x24,0x23,0x24,0x23,0x24,0x00,0xee,0x6c,0x00,0x23,0x50,0x23,0x50,0x23,0x50,0x23
,0x50,0x00,0xee,0xa6,0x83,0xfe,0x1e,0xfe,0x1e,0xfe,0x1e,0xfe,0x1e,0xfc,0x1e,0xf1,0x65,0xa4,0x7c,0xd0,0x14,0x7c,0x02,0x00,0xee,0xa9,0x83,0xfe,0x1e,0xfe,0x1e,0xfe
,0x1e,0xfe,0x1e,0xfc,0x1e,0xf1,0x65,0xa4,0x7c,0xd0,0x14,0x7c,0x02,0x00,0xee,0xab,0x83,0xfe,0x1e,0xfe,0x1e,0xfe,0x1e,0xfe,0x1e,0xfc,0x1e,0xf1,0x65,0xa4,0x7c,0xd0
,0x14,0x7c,0x02,0x00,0xee,0x6c,0x00,0x60,0x1f,0x8a,0xd0,0x8a,0xc4,0x8a,0x02,0x8a,0x94,0xad,0x83,0xfa,0x1e,0xfa,0x1e,0xf1,0x65,0xa4,0x80,0xd0,0x13,0x7c,0x01,0x3c
,0x08,0x13,0x68,0x00,0xee,0x60,0x1f,0x8a,0xd0,0x8a,0x02,0x8a,0x94,0xad,0x83,0xfa,0x1e,0xfa,0x1e,0xf1,0x65,0xa4,0x80,0xd0,0x13,0x60,0x1f,0x8a,0xd0,0x7a,0x08,0x8a
,0x02,0x8a,0x94,0xad,0x83,0xfa,0x1e,0xfa,0x1e,0xf1,0x65,0xa4,0x80,0xd0,0x13,0x00,0xee,0xa6,0x83,0xfd,0x1e,0xf0,0x65,0x30,0x00,0xf0,0x18,0x00,0xee,0xf0,0x07,0x30
,0x00,0x13,0xbe,0x00,0xee,0x6d,0x04,0x61,0x0c,0x60,0x1c,0x62,0x12,0xa4,0x1e,0xf2,0x1e,0xd0,0x16,0xfd,0x15,0x23,0xbe,0x60,0x14,0x62,0x0c,0xa4,0x1e,0xf2,0x1e,0xd0
,0x16,0x60,0x24,0x62,0x18,0xa4,0x1e,0xf2,0x1e,0xd0,0x16,0xfd,0x15,0x23,0xbe,0x60,0x0c,0x62,0x06,0xa4,0x1e,0xf2,0x1e,0xd0,0x16,0x60,0x2c,0x62,0x1e,0xa4,0x1e,0xf2
,0x1e,0xd0,0x16,0xfd,0x15,0x23,0xbe,0xa4,0x1e,0x60,0x04,0xd0,0x16,0x60,0x34,0x62,0x24,0xa4,0x1e,0xf2,0x1e,0xd0,0x16,0xfd,0x15,0x23,0xbe,0x00,0xee,0x00,0x00,0x0c
,0x11,0x11,0x10,0x00,0x00,0x95,0x55,0x95,0xcd,0x00,0x00,0x53,0x55,0x55,0x33,0x40,0x40,0x44,0x42,0x41,0x46,0x00,0x40,0x6a,0x4a,0x4a,0x46,0x00,0x20,0x69,0xaa,0xaa
,0x69,0x00,0x00,0x20,0x90,0x88,0x30,0x64,0x01,0x65,0x07,0x62,0x00,0x63,0x00,0x60,0x00,0x81,0x30,0xd0,0x11,0x71,0x08,0xf4,0x1e,0xd0,0x11,0x71,0x08,0xf4,0x1e,0xd0
,0x11,0x71,0x08,0xf4,0x1e,0xd0,0x11,0xf4,0x1e,0x70,0x08,0x30,0x40,0x14,0x52,0x73,0x03,0x83,0x52,0x72,0x01,0x32,0x08,0x14,0x50,0x00,0xee,0x60,0xb0,0xf0,0x60,0x40
,0xa0,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0xc6,0x00,0x00,0x00,0xdb,0x00,0x00,0x00,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x5f,0x06,0x00,0x00,0xfe,0xc6,0x00,0x00,0xd3,0xfb,0x00,0x00,0xf0,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0xf6,0x00,0x00,0x00,0xfb,0xe0,0x00,0x00,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x06,0x00,0x00,0x00,0xc6,0x00,0x00,0x00,0xdb,0x00,0x00,0x00,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x06,0x00,0x00,0x00,0xc6,0x00,0x00,0x03,0xf1,0x00,0x00,0x30,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0xc6,0x00,0x00,0x00,0xd9,0x00,0x00,0x00,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2f,0x06,0x00,0x00,0xff,0xc6,0x00,0x00,0x69,0xdb,0x00,0x00,0xe0,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x76,0x00,0x00,0x00,0xf3,0xe0,0x00,0x00,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1f,0x07,0x0f,0x00,0xff,0xfe,0xfc,0x7e,0x00,0x00
,0x3e,0x7c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2f,0x1b,0x07,0x00,0xff,0xf0,0xfb,0x1f,0x00,0x00
,0xfe,0xb0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x17,0x0f,0x00,0x00,0xff,0xf8,0x7e,0x0f,0x00,0x0c
,0x14,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2f,0x0b,0x0f,0x00,0xfe,0xe0,0xfc,0x3f,0x00,0x00
,0x7e,0xfc,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x17,0x1f,0x03,0x00,0xff,0xf0,0xff,0x1f,0x80,0x00
,0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0b,0x0f,0x00,0x00,0xfe,0xf8,0x7e,0x0f,0x00,0x1c
,0x3e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x17,0x17,0x0f,0x00,0xfe,0xc0,0xf8,0x3f,0x00,0x00
,0xfe,0xfc,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2b,0x1f,0x00,0x00,0xff,0xe0,0x7f,0x1f,0x80,0x04
,0x1c,0x3c,0x04,0x05,0x1b,0x05,0x1b,0x17,0x04,0x17,0x07,0x08,0x17,0x08,0x1c,0x08,0x15,0x1a,0x06,0x03,0x00,0x14,0x1b,0x0a,0x16,0x16,0x1a,0x0a,0x0e,0x1a,0x08,0x02
,0x00,0x10,0x1e,0x0c,0x15,0x17,0x18,0x0b,0x08,0x19,0x0b,0x01,0x00,0x0d,0x20,0x0f,0x13,0x19,0x15,0x0a,0x03,0x15,0x20,0x12,0x0e,0x01,0x10,0x1a,0x01,0x0b,0x14,0x08
,0x00,0x11,0x1f,0x14,0x0d,0x1b,0x12,0x01,0x04,0x09,0x15,0x06,0x00,0x0d,0x1d,0x16,0x0a,0x1b,0x15,0x03,0x06,0x08,0x18,0x05,0x01,0x09,0x1c,0x16,0x06,0x19,0x17,0x05
,0x07,0x08,0x1b,0x05,0x04,0x05,0x1b,0x17,0x04,0x17,0x17,0x08,0x08,0x08,0x04,0x14,0x09,0x02,0x1a,0x18,0x1e,0x07,0x05,0x13,0x08,0x07,0x05,0x12,0x0e,0x01,0x19,0x19
,0x1f,0x0a,0x02,0x12,0x08,0x06,0x08,0x12,0x14,0x02,0x18,0x1a,0x20,0x0c,0x00,0x10,0x09,0x05,0x0a,0x12,0x19,0x04,0x15,0x1b,0x00,0x0e,0x1f,0x0e,0x0b,0x03,0x0c,0x14
,0x1d,0x08,0x00,0x0b,0x0e,0x01,0x11,0x1b,0x1d,0x11,0x0b,0x17,0x1f,0x0d,0x00,0x08,0x12,0x01,0x0d,0x1a,0x1b,0x12,0x08,0x18,0x1e,0x12,0x02,0x07,0x17,0x02,0x0a,0x17
,0x19,0x13,0x1b,0x17,0x1b,0x05,0x04,0x17,0x04,0x05,0x17,0x08,0x17,0x14,0x1d,0x0a,0x06,0x04,0x15,0x1a,0x01,0x15,0x1b,0x09,0x0b,0x05,0x1b,0x0e,0x08,0x03,0x0e,0x1b
,0x00,0x11,0x1e,0x0c,0x10,0x04,0x17,0x12,0x0a,0x02,0x08,0x1a,0x1f,0x0f,0x00,0x0d,0x16,0x04,0x10,0x14,0x0d,0x02,0x1e,0x14,0x03,0x16,0x1b,0x06,0x02,0x09,0x09,0x13
,0x10,0x01,0x1a,0x18,0x1f,0x0a,0x01,0x12,0x07,0x06,0x04,0x0f,0x14,0x02,0x13,0x1b,0x20,0x0e,0x01,0x0e,0x0d,0x05,0x02,0x0a,0x18,0x03,0x0b,0x1b,0x1f,0x13,0x04,0x0a
,0x12,0x05,0x04,0x17,0x04,0x05,0x1b,0x17,0x1b,0x05,0x08,0x14,0x08,0x08,0x15,0x19,0x1e,0x08,0x00,0x11,0x09,0x02,0x14,0x17,0x1b,0x0c,0x0e,0x17,0x1f,0x0b,0x00,0x0b
,0x0f,0x01,0x10,0x1a,0x1c,0x10,0x09,0x13,0x1f,0x0e,0x02,0x06,0x15,0x02,0x0a,0x1a,0x1a,0x15,0x08,0x0e,0x1f,0x0f,0x08,0x02,0x05,0x18,0x1a,0x05,0x17,0x19,0x0a,0x09
,0x1e,0x12,0x00,0x14,0x0e,0x01,0x11,0x1b,0x1c,0x09,0x0f,0x05,0x1d,0x14,0x00,0x0e,0x0c,0x1b,0x13,0x02,0x1d,0x0e,0x15,0x04,0x1c,0x15,0x00,0x0a,0x07,0x1a,0x16,0x05
,0x1b,0x11,0x1b,0x05,0x04,0x05,0x04,0x17,0x1b,0x17,0x18,0x08,0x08,0x08,0x03,0x14,0x0a,0x02,0x19,0x19,0x1f,0x08,0x04,0x12,0x09,0x06,0x05,0x12,0x11,0x02,0x17,0x1a
,0x20,0x0c,0x01,0x10,0x0a,0x05,0x07,0x11,0x17,0x03,0x14,0x1b,0x00,0x0d,0x20,0x0f,0x0c,0x03,0x0a,0x12,0x1c,0x07,0x00,0x0a,0x11,0x1b,0x0f,0x02,0x1e,0x11,0x0b,0x14
,0x1f,0x0b,0x00,0x08,0x12,0x01,0x0d,0x1b,0x1b,0x13,0x0a,0x16,0x1f,0x0f,0x02,0x06,0x15,0x01,0x0a,0x19,0x19,0x14,0x07,0x17,0x1e,0x13,0x03,0x06,0x19,0x03,0x08,0x17
,0x18,0x14,0x1b,0x05,0x04,0x05,0x1b,0x17,0x04,0x17,0x17,0x08,0x08,0x08,0x1b,0x08,0x16,0x1a,0x05,0x04,0x01,0x15,0x1a,0x09,0x17,0x15,0x1a,0x0a,0x11,0x1b,0x06,0x03
,0x00,0x12,0x1d,0x0a,0x17,0x16,0x17,0x0a,0x0b,0x1a,0x07,0x02,0x00,0x10,0x1f,0x0c,0x16,0x17,0x15,0x0a,0x06,0x18,0x0a,0x01,0x20,0x0e,0x00,0x0e,0x14,0x19,0x13,0x08
,0x02,0x14,0x20,0x11,0x0e,0x01,0x11,0x1b,0x02,0x0b,0x14,0x05,0x00,0x0f,0x1f,0x14,0x0d,0x1b,0x12,0x02,0x04,0x0a,0x17,0x04,0x01,0x0a,0x1d,0x15,0x08,0x1a,0x15,0x05
,0x06,0x09,0x1b,0x17,0x1b,0x05,0x04,0x17,0x04,0x05,0x18,0x08,0x18,0x14,0x02,0x12,0x19,0x18,0x0a,0x02,0x1e,0x07,0x04,0x13,0x14,0x17,0x04,0x0e,0x17,0x19,0x11,0x01
,0x20,0x0b,0x01,0x10,0x0f,0x18,0x08,0x0a,0x15,0x1a,0x17,0x02,0x20,0x0f,0x00,0x0d,0x09,0x18,0x0f,0x08,0x12,0x1a,0x01,0x08,0x1c,0x06,0x04,0x16,0x1d,0x13,0x16,0x09
,0x0f,0x1b,0x05,0x04,0x00,0x12,0x1e,0x0a,0x18,0x16,0x1b,0x0d,0x0b,0x1a,0x0c,0x01,0x00,0x0e,0x1e,0x0e,0x12,0x17,0x1d,0x12,0x07,0x19,0x14,0x01,0x00,0x09,0x1b,0x12
,0x0d,0x17,0x04,0x17,0x04,0x05,0x1b,0x17,0x1b,0x05,0x08,0x14,0x08,0x08,0x0a,0x03,0x01,0x14,0x1f,0x0b,0x16,0x1a,0x0b,0x05,0x04,0x10,0x11,0x05,0x00,0x11,0x20,0x11
,0x10,0x1b,0x0f,0x02,0x03,0x0c,0x16,0x09,0x00,0x0e,0x1d,0x16,0x0a,0x1a,0x15,0x02,0x05,0x07,0x17,0x0e,0x00,0x0d,0x17,0x1a,0x1a,0x04,0x05,0x17,0x08,0x03,0x15,0x13
,0x01,0x0a,0x1f,0x08,0x0e,0x01,0x11,0x1b,0x03,0x13,0x10,0x17,0x02,0x08,0x20,0x0e,0x13,0x01,0x0c,0x1a,0x02,0x0e,0x0a,0x18,0x03,0x07,0x1f,0x12,0x18,0x02,0x09,0x17
,0x04,0x0b,0x04,0x05,0x1b,0x05,0x1b,0x17,0x04,0x17,0x1c,0x08,0x15,0x1a,0x06,0x03,0x00,0x14,0x1a,0x0a,0x0e,0x1a,0x08,0x02,0x00,0x10,0x18,0x0b,0x08,0x19,0x0b,0x01
,0x00,0x0d,0x15,0x0a,0x03,0x15,0x0e,0x01,0x01,0x0b,0x14,0x08,0x00,0x11,0x12,0x01,0x14,0x12,0x15,0x06,0x00,0x0d,0x13,0x14,0x15,0x03,0x18,0x05,0x01,0x09,0x11,0x15
,0x17,0x05,0x1b,0x05,0x04,0x05,0x10,0x15,0x17,0x08,0x09,0x02,0x1e,0x07,0x0e,0x15,0x08,0x07,0x0e,0x01,0x1f,0x0a,0x0c,0x15,0x08,0x06,0x14,0x02,0x0b,0x14,0x20,0x0c
,0x09,0x05,0x19,0x04,0x0a,0x14,0x1f,0x0e,0x0b,0x03,0x1d,0x08,0x08,0x13,0x0e,0x01,0x1d,0x11,0x1f,0x0d,0x12,0x01,0x07,0x11,0x1b,0x12,0x1e,0x12,0x17,0x02,0x06,0x10
,0x19,0x13,0x1b,0x17,0x1b,0x05,0x06,0x0e,0x17,0x08,0x1d,0x0a,0x15,0x1a,0x07,0x0c,0x1b,0x09,0x1b,0x0e,0x0e,0x1b,0x08,0x0a,0x1e,0x0c,0x17,0x12,0x08,0x1a,0x1f,0x0f
,0x0b,0x08,0x10,0x14,0x1e,0x14,0x03,0x16,0x0f,0x07,0x09,0x13,0x1a,0x18,0x01,0x12,0x12,0x08,0x04,0x0f,0x13,0x1b,0x15,0x09,0x01,0x0e,0x02,0x0a,0x0b,0x1b,0x18,0x0b
,0x04,0x0a,0x04,0x17,0x04,0x05,0x19,0x0e,0x08,0x14,0x00,0x11,0x09,0x02,0x18,0x10,0x06,0x12,0x00,0x0b,0x0f,0x01,0x16,0x13,0x05,0x10,0x02,0x06,0x14,0x14,0x15,0x02
,0x05,0x0e,0x11,0x14,0x08,0x02,0x1a,0x05,0x05,0x0d,0x0e,0x13,0x0e,0x01,0x1c,0x09,0x06,0x0c,0x0d,0x11,0x13,0x02,0x1d,0x0e,0x06,0x0a,0x0e,0x0f,0x16,0x05,0x1b,0x11
,0x07,0x09,0x10,0x0e,0x18,0x08,0x08,0x08,0x08,0x14,0x12,0x0e,0x04,0x12,0x09,0x06,0x13,0x16,0x14,0x0e,0x01,0x10,0x0a,0x05,0x0f,0x16,0x16,0x10,0x00,0x0d,0x0c,0x03
,0x0a,0x15,0x16,0x12,0x00,0x0a,0x0f,0x02,0x07,0x13,0x00,0x08,0x15,0x13,0x12,0x01,0x05,0x10,0x02,0x06,0x15,0x01,0x13,0x15,0x05,0x0e,0x03,0x06,0x19,0x03,0x11,0x15
,0x05,0x0b,0x1b,0x05,0x04,0x05,0x0f,0x15,0x17,0x08,0x1b,0x08,0x05,0x04,0x0e,0x15,0x1a,0x09,0x1a,0x0a,0x06,0x03,0x0c,0x14,0x1d,0x0a,0x17,0x0a,0x07,0x02,0x1f,0x0c
,0x0b,0x14,0x15,0x0a,0x0a,0x01,0x20,0x0e,0x0a,0x13,0x13,0x08,0x20,0x11,0x0e,0x01,0x09,0x12,0x14,0x05,0x1f,0x14,0x08,0x11,0x12,0x02,0x17,0x04,0x1d,0x15,0x07,0x10
,0x15,0x05,0x1b,0x17,0x1b,0x05,0x06,0x0e,0x18,0x08,0x19,0x18,0x1e,0x07,0x07,0x0c,0x14,0x17,0x17,0x19,0x20,0x0b,0x08,0x0a,0x0f,0x18,0x15,0x1a,0x0b,0x08,0x20,0x0f
,0x09,0x18,0x12,0x1a,0x0e,0x07,0x04,0x16,0x1d,0x13,0x0f,0x1b,0x12,0x07,0x00,0x12,0x18,0x16,0x0b,0x1a,0x00,0x0e,0x16,0x09,0x12,0x17,0x07,0x19,0x00,0x09,0x18,0x0b
,0x0d,0x17,0x04,0x17,0x04,0x05,0x19,0x0e,0x08,0x14,0x0a,0x03,0x01,0x14,0x18,0x10,0x0b,0x05,0x11,0x05,0x00,0x11,0x16,0x12,0x0f,0x02,0x16,0x09,0x00,0x0e,0x15,0x02
,0x13,0x13,0x17,0x0e,0x00,0x0d,0x1a,0x04,0x08,0x03,0x15,0x13,0x01,0x0a,0x1f,0x08,0x0e,0x01,0x10,0x17,0x02,0x08,0x20,0x0e,0x13,0x01,0x0a,0x18,0x03,0x07,0x1f,0x12
,0x18,0x02,0x10,0x0e,0x06,0x07,0x19,0x07,0x19,0x15,0x0d,0x0e,0x1b,0x09,0x16,0x17,0x09,0x05,0x0b,0x0e,0x1c,0x0c,0x12,0x18,0x0d,0x04,0x1c,0x0e,0x09,0x0c,0x0e,0x19
,0x11,0x04,0x1b,0x0e,0x09,0x0a,0x0b,0x18,0x14,0x05,0x1a,0x0e,0x07,0x16,0x0a,0x09,0x14,0x12,0x1a,0x0e,0x05,0x14,0x0c,0x07,0x13,0x14,0x1a,0x0e,0x04,0x11,0x0e,0x07
,0x11,0x15,0x1b,0x0e,0x04,0x0e,0x10,0x15,0x10,0x07,0x06,0x0c,0x1c,0x0f,0x0e,0x15,0x11,0x07,0x0a,0x0a,0x1d,0x10,0x0c,0x15,0x13,0x08,0x0e,0x0a,0x1c,0x12,0x0b,0x14
,0x14,0x08,0x12,0x0b,0x0a,0x14,0x1a,0x14,0x05,0x08,0x15,0x0e,0x07,0x06,0x08,0x13,0x17,0x16,0x15,0x11,0x0a,0x04,0x07,0x11,0x17,0x0b,0x13,0x15,0x0d,0x04,0x06,0x10
,0x18,0x0c,0x10,0x17,0x10,0x05,0x06,0x0e,0x19,0x0e,0x11,0x07,0x0b,0x17,0x18,0x10,0x07,0x0c,0x11,0x09,0x06,0x16,0x17,0x12,0x08,0x0a,0x10,0x0a,0x03,0x13,0x14,0x14
,0x1a,0x0a,0x0e,0x0b,0x11,0x15,0x1d,0x0d,0x03,0x0f,0x0d,0x0a,0x1d,0x10,0x0d,0x15,0x12,0x08,0x0c,0x08,0x1a,0x14,0x09,0x13,0x15,0x09,0x0d,0x06,0x15,0x17,0x07,0x11
,0x18,0x0b,0x10,0x17,0x10,0x05,0x19,0x0e,0x06,0x0e,0x0a,0x15,0x13,0x05,0x18,0x10,0x07,0x0c,0x06,0x10,0x17,0x05,0x16,0x13,0x09,0x0a,0x05,0x0c,0x1a,0x07,0x14,0x14
,0x0c,0x09,0x08,0x07,0x11,0x14,0x1c,0x0a,0x05,0x11,0x0c,0x04,0x0e,0x13,0x1d,0x0d,0x04,0x0f,0x0d,0x11,0x11,0x03,0x1d,0x10,0x03,0x0d,0x0e,0x0f,0x16,0x04,0x1b,0x13
,0x04,0x09,0x10,0x0e,0x19,0x07,0x06,0x07,0x06,0x15,0x12,0x0e,0x04,0x13,0x09,0x05,0x16,0x17,0x14,0x0e,0x03,0x10,0x0d,0x04,0x12,0x18,0x03,0x0e,0x16,0x10,0x11,0x03
,0x0e,0x18,0x04,0x0e,0x16,0x12,0x14,0x04,0x0b,0x17,0x05,0x0e,0x18,0x06,0x15,0x13,0x0b,0x0a,0x05,0x0e,0x1a,0x08,0x13,0x15,0x0c,0x08,0x05,0x0e,0x1b,0x0b,0x11,0x15
,0x0e,0x07,0x1b,0x0e,0x04,0x0e,0x0f,0x15,0x0f,0x07,0x19,0x10,0x03,0x0d,0x11,0x07,0x0e,0x15,0x15,0x12,0x02,0x0c,0x13,0x07,0x0c,0x14,0x11,0x12,0x03,0x0a,0x14,0x08
,0x0b,0x14,0x0d,0x11,0x15,0x08,0x05,0x08,0x1a,0x14,0x0a,0x0e,0x18,0x16,0x17,0x09,0x08,0x06,0x0a,0x0b,0x15,0x18,0x18,0x0b,0x08,0x11,0x0c,0x07,0x12,0x18,0x19,0x0c
,0x07,0x10,0x10,0x17,0x10,0x05,0x06,0x0e,0x19,0x0e,0x0e,0x15,0x14,0x05,0x07,0x0c,0x18,0x10,0x0e,0x13,0x19,0x06,0x08,0x0a,0x17,0x12,0x0f,0x12,0x1c,0x09,0x0b,0x08
,0x05,0x12,0x11,0x11,0x0e,0x07,0x02,0x0f,0x1c,0x0d,0x12,0x12,0x02,0x0c,0x12,0x07,0x0d,0x14,0x13,0x14,0x05,0x08,0x16,0x09,0x0a,0x13,0x12,0x16,0x0a,0x05,0x18,0x0b
,0x07,0x11,0x0f,0x17,0x10,0x05,0x19,0x0e,0x06,0x0e,0x15,0x07,0x0c,0x17,0x07,0x0c,0x18,0x10,0x19,0x0c,0x08,0x17,0x09,0x09,0x16,0x12,0x1a,0x10,0x05,0x15,0x0b,0x08
,0x13,0x13,0x17,0x15,0x0e,0x08,0x03,0x12,0x1a,0x0b,0x13,0x18,0x11,0x09,0x02,0x0f,0x1b,0x0d,0x12,0x0b,0x0e,0x19,0x02,0x0c,0x1c,0x0f,0x11,0x0d,0x09,0x18,0x04,0x09
,0x1b,0x13,0x10,0x10,0x0c,0x14,0x07,0x17,0x04,0x1a,0x03,0x1c,0x03,0x1d,0x05,0x1d,0x08,0x1b,0x0c,0x19,0x10,0x16,0x14,0x13,0x17,0x10,0x1a,0x0d,0x1b,0x0a,0x1b,0x08
,0x19,0x06,0x17,0x05,0x13,0x06,0x10,0x07,0x0d,0x08,0x0a,0x0b,0x07,0x0e,0x06,0x10,0x06,0x12,0x08,0x15,0x0a,0x17,0x0d,0x18,0x10,0x19,0x13,0x19,0x16,0x18,0x18,0x17
,0x19,0x14,0x10,0x19,0x0f,0x17,0x0d,0x17,0x0a,0x19,0x06,0x1a,0x06,0x16,0x09,0x13,0x09,0x11,0x07,0x10,0x03,0x0e,0x03,0x0b,0x08,0x0b,0x0b,0x0b,0x0c,0x0a,0x0c,0x06
,0x0e,0x02,0x10,0x04,0x11,0x08,0x12,0x0a,0x14,0x09,0x19,0x07,0x1b,0x09,0x19,0x0d,0x17,0x0f,0x17,0x10,0x1a,0x12,0x1d,0x15,0x1a,0x16,0x15,0x15,0x14,0x16,0x13,0x18
,0x12,0x1d,0x10,0x19,0x0e,0x17,0x0d,0x17,0x0b,0x17,0x08,0x17,0x05,0x19,0x02,0x19,0x03,0x17,0x08,0x14,0x0b,0x12,0x0e,0x11,0x10,0x10,0x11,0x10,0x14,0x0e,0x19,0x0b
,0x1c,0x09,0x1c,0x09,0x19,0x09,0x17,0x0a,0x16,0x0a,0x14,0x09,0x13,0x07,0x11,0x04,0x0f,0x02,0x0b,0x03,0x09,0x06,0x09,0x09,0x09,0x0a,0x09,0x0b,0x08,0x0b,0x07,0x0b
,0x07,0x0b,0x10,0x19,0x13,0x18,0x15,0x17,0x16,0x16,0x18,0x15,0x18,0x15,0x18,0x14,0x15,0x12,0x10,0x10,0x0b,0x0e,0x09,0x0c,0x08,0x0c,0x09,0x0b,0x0a,0x0a,0x0b,0x09
,0x0d,0x08,0x10,0x06,0x14,0x04,0x1a,0x03,0x1d,0x04,0x1c,0x08,0x19,0x0b,0x15,0x0d,0x12,0x0f,0x10,0x10,0x0d,0x11,0x0a,0x13,0x06,0x16,0x03,0x19,0x03,0x1c,0x07,0x1c
,0x0c,0x1a,0x00};
const int romTrip8_size=3204;



/* Debug write buffer */
static char debug [60];

/* Define shorthanded named types */
typedef unsigned char byte;
typedef unsigned short uint16;
typedef signed short int16;
typedef unsigned long uint32;
typedef unsigned long long uint64;
typedef signed long long int64;
typedef signed long int32;
//typedef void __attribute__((__interrupt__, __shadow__)) (_interrupt) (void);

/* Empty debug function */
void empty(char * x, ...) { }

const char *byte_to_binary(int x)
{
    static char b[9];
    b[0] = '\0';

    int z;
    for (z = 128; z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }

    return b;
}

/* Causes a loop-based delay */
void delay_routine(void)
{
    __delay_ms(200);
}

#ifdef DEBUG
#if defined(GLCD)
#define DEBUG_WRITE(format, args...) \
    sprintf(debug, format , ##args); \
    GLCD_WRITE(debug)
#else
#define DEBUG_WRITE(format, args...) printf(format , ##args)
#endif
#else
#define DEBUG_WRITE(format, args...) empty(format, ##args);
#endif //DEBUG

#if defined(DEBUG_I2C)
#define I2CDebug(x, args...) \
    DEBUG_WRITE(x , ##args); \
    delay_routine()
#else
    #define I2CDebug(x, args...) empty(x , ##args)
#endif // DEBUG_I2C

void I2CIdleWait(void)
{
    while (I2C1CON & 0x1F);
    while (I2C1STATbits.TRSTAT);
}

void I2CStart(void)
{
    I2CIdleWait();
    I2C1CONbits.SEN = 1;
    while (I2C1CONbits.SEN);
    I2CDebug("Start");
}

void I2CStop(void)
{
    I2CIdleWait();
    I2C1CONbits.PEN = 1; // Initiate Stop condition on SDAx and SCLx
    while(I2C1CONbits.PEN); // bit = 0 --- Stop condition not in progress
    I2CDebug("Stop");
}

void I2CRestart(void)
{
    I2CIdleWait();
    I2C1CONbits.RSEN = 1; // Initiate Repeated Start condition on SDAx
    while(I2C1CONbits.RSEN); // bit = 0 --- Repeated Start condition not in
    I2CDebug("Restart");
}

void I2CAck(void)
{
    I2CIdleWait();
    I2C1CONbits.ACKDT = 0; // 0 = Send ACK during Acknowledge
    I2C1CONbits.ACKEN = 1; // 1 = Initiate Acknowledge sequence on
    while(I2C1CONbits.ACKEN); // bit = 0 --- Acknowledge sequence not in
    I2CDebug("Ack");
}

void I2CAckWait(void)
{
    I2CDebug("Ack Wait");
    while (I2C1STATbits.TRSTAT & I2C1STATbits.ACKSTAT);
}

void I2CNackWait(void)
{
    I2CDebug("Nack Wait");
    while (I2C1STATbits.TRSTAT & !I2C1STATbits.ACKSTAT);
}

void I2CNack(void) // Acknowledge Data bit
{
    I2CIdleWait();
    I2C1CONbits.ACKDT = 1; // 1 = Send NACK during Acknowledge
    I2C1CONbits.ACKEN = 1; // 1 = Initiate Acknowledge sequence on
    while(I2C1CONbits.ACKEN); // bit = 0 --- Acknowledge sequence not in
    I2CDebug("Nack");
}

void I2CInit(void)
{
    I2C1BRG = 34; // Baud Rate Generator
    I2C1CONbits.I2CEN = 1; // 0 = Disables the I2Cx module. All I2C pins
    I2C1CONbits.DISSLW = 1; // 0 = Slew rate control disabled
    I2CDebug("I2C Init");
}

void I2CBusIdleWait(void)
{
    while (I2C1STATbits.TRSTAT);
}

byte I2CReadByte(void)
{
    byte read = 0;
    I2C1CONbits.RCEN = 1;
    while (I2C1CONbits.RCEN & !I2C1STATbits.RBF) ;
    
    if (I2C1STATbits.BCL)
    {
        DEBUG_WRITE("R: Bus Coll.");
        while (1) { }
    }
    
    if (I2C1STATbits.I2COV)
    {
        DEBUG_WRITE("Overflow in RCV");
        while (1) { }
    }
    
    I2CIdleWait();
    read = (byte)(I2C1RCV & 0xFF);
    I2CDebug("R: 0x%02x", read);
    return read;
}

void I2CWriteByte(byte byte)
{
    if (I2C1STATbits.BCL)
    {
        DEBUG_WRITE("W: Bus Coll.");
        while (1) { }
    }
    
    I2C1TRN = byte;
    while (I2C1STATbits.TBF);
    I2CIdleWait();
    I2CAckWait();
    I2CDebug("W: 0x%02x", byte);
}

#define BlockSelect(x) x >= 0x8000 ? 1 : 0

byte __inline__ EEPROMGetControlByte(uint16 eepromAddress, uint16 slaveAddress, byte readMode)
{
    return (0xA << 4 | ((BlockSelect(eepromAddress) & 1) << 3) | ((slaveAddress & 3) << 1) | (readMode & 1));
}

void EEPROMWriteControlByte(uint16 eepromAddress, uint16 slaveAddress, byte readMode)
{
    byte c = EEPROMGetControlByte(eepromAddress, slaveAddress, readMode);
    I2CWriteByte(c);
}

void EEPROMWriteAddressBytes(uint16 eepromAddress)
{
    /* High */
    I2CWriteByte((eepromAddress >> 8) & 0xFF);
    
    /* Low */
    I2CWriteByte(eepromAddress & 0xFF);
}

void EEPROMReadBytes(
    byte * const buffer,
    int count,
    uint16 slaveAddress, 
    uint16 eepromAddress)
{
    int i = 0;
    
    I2C1ADD = slaveAddress;
        
    I2CStart();
    
    EEPROMWriteControlByte(eepromAddress, slaveAddress, 0);    
    EEPROMWriteAddressBytes(eepromAddress);
    
    I2CStart();
    
    EEPROMWriteControlByte(eepromAddress, slaveAddress, 1);
    
    if (count > 1)
    {
        for (i = 0; i < count && i < 64; i++)
        {
            *(buffer + i) = I2CReadByte();

            if ((i + 1) < count)
            {
                I2CAck();
            }
            else
            {
                I2CNack();
            }
        }
    }
    else
    {
        *buffer = I2CReadByte();
        I2CNack();
    }
    
    I2CStop();
}

void EEPROMWriteBytes(
    const byte * buffer,
    int count,
    uint16 slaveAddress, 
    uint16 eepromAddress)
{
    int i = 0;
    
    I2C1ADD = slaveAddress;
        
    I2CStart();
    
    EEPROMWriteControlByte(eepromAddress, slaveAddress, 0);    
    EEPROMWriteAddressBytes(eepromAddress);
    
    if (count > 1)
    {
        for (i = 0; i < count && i < 64; i++)
        {
           I2CWriteByte(*(buffer + i));
        }
    }
    else
    {
        I2CWriteByte(*buffer);
    }
    
    
    I2CStop();
    
    __delay_ms(5);
}

#define PAGE_MAX_SIZE 64

uint16 EEPROMFlashRom(char * name, const byte * buffer, const uint16 size, const uint16 address)
{
    int i = 0;
    uint16 cAddress = address;
    uint16 cOffset = 0;
    uint16 cSize = size;
    
    DEBUG_WRITE("FL: %s", name);
    
    for (i = 0; i < size; i++)
    {
            EEPROMWriteBytes((buffer + cOffset), 1, 0, cAddress);
            cAddress++;
            cOffset++;
            cSize--;
    }
    
        /* Verify byte by byte*/
    DEBUG_WRITE("Verify...");
    byte read [1];
    for (i = 0; i < size; i++)
    {
        EEPROMReadBytes(&read[0], 1, 0, address + i);
        if (*(buffer + i) != read[0])
        {
            DEBUG_WRITE("%04X %02X %02X %02X", address + i, read[0], i, *(buffer + i));
            while (1) {}
        }
    }
    
    DEBUG_WRITE("Write Done");
    
    return size;
}
#define ROM_ARG(x) (byte *)&rom##x
#define ROM_FLASH(x) address += EEPROMFlashRom(#x, ROM_ARG(x), rom##x##_size, address);

/* Main program entry point */
int main(void) 
{
    uint16 address = 0;
    
    /* Init the LCD and setup text write mode */
    #if defined(GLCD)
        glcd_init();
        GLCD_TEXT_INIT();
        glcd_clear_buffer();
    #endif

    DEBUG_WRITE("Start");
    
    I2CInit();
    
    ROM_FLASH(Font);
    ROM_FLASH(Chip8);
    ROM_FLASH(Sctest);
    ROM_FLASH(Maze);
    ROM_FLASH(Pong);
    ROM_FLASH(Simple);
    ROM_FLASH(JXO);
    ROM_FLASH(Space);
    ROM_FLASH(Trip8);
    
    DEBUG_WRITE("ALL DONE");
    
    while (1)
    {
    }
   
    return 0;
}

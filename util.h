/*
 * Copyright (C) 2010 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _INIT_UTIL_H_
#define _INIT_UTIL_H_

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>
#include <time.h>

#define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))

time_t gettime(void);
unsigned int decode_uid(const char *s);
int mkdir_recursive(const char *pathname, mode_t mode);
void sanitize(char *p);
int make_link(const char *oldpath, const char *newpath);
void remove_link(const char *oldpath, const char *newpath);
int wait_for_file(const char *filename, int timeout);
int copy_file(const char *from, const char *to);
int mkdir_with_perms(const char *path, mode_t mode, const char *owner, const char *group);
int write_file(const char *path, const char *value);
int remove_dir(const char *dir);
int run_cmd(char **cmd);
char *run_get_stdout(char **cmd);
char *readlink_recursive(const char *link);
void stdio_to_null();
char *parse_string(char *src);
uint32_t timespec_diff(struct timespec *f, struct timespec *s);
void emergency_remount_ro(void);

inline int imin(int a, int b);
inline int imax(int a, int b);
inline int in_rect(int x, int y, int rx, int ry, int rw, int rh);
inline void *mzalloc(size_t size); // alloc and fill with 0s

#endif

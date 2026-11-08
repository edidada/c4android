[创建文件参考博文](http://blog.csdn.net/the01hierarch/article/details/24989725)

[编译文件参考博文](http://blog.csdn.net/wangzhiyu1980/article/details/16972937)

[win下使用ndk-build.cmd的方案](http://blog.csdn.net/daizhongyin/article/details/52795561)


- windows平台下创建c文件
- 使用安卓交叉编译工具编译
- adb传输到手机
- 修改文件权限
- 执行


### 1. 安装NDK；
### 2. 编写hello.c源文件

```c
#include <stdio.h>
int main() {
        printf("hello, arm c world!\n");
        return 0;
}

```

### 3.可以直接使用ndk-build命令来编译
a. 新建目录 workspace;
b. 进入workspace，新建目录jni；
c. 进入jni，新建hello.c文件，输入源文件内容；
d. 新建Android.mk文件，内容如下：

```shell

LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)
LOCAL_SRC_FILES:= hello.c
LOCAL_MODULE := libtest
include $(BUILD_EXECUTABLE)

```

e. 运行ndk-build命令，可看到在workspace目录下生成了libs和obj两个目录，libs下对应的armeabi文件夹下有生成的可执行文件 test

### 4. 放到android设备上运行

```shell
adb push test /data/local/tmp/test

adb shell /data/local/tmp/test

```

### 5、修改权限
但如果尝试在sdcard 中运行程序多半会遇到一个Permision Denied一个错误。

我们可以简单尝试使用 chmod 777 HelloWorld来修复它，但再次运行程序时多半还会失败。

网上找了找原因，给出的解释是Android不能修改 sdcard下 程序的权限，最简单的老老实实把它复制到Android系统下的某个文件夹下吧。



4)  cp /mnt/sdcard/HelloWorld  /data/    复制文件到Android的data目录下

5)  chmod 777 HelloWorld  修改权限

6)  ls -l 当然可以在查询一下，但也不是必须的。

### 6. 看到输出结果：

```
hello, arm c world!

```
---

## tbox 数据库连接测试

在原来的 hello 程序基础上增加了 [tbox](https://github.com/tboox/tbox) 与 SQLite，
用 tbox 的 database API 实际打开一个 SQLite 数据库并执行 SQL。

目录说明：

- `thirdparty/tbox`：tbox 源码（git submodule）
- `scripts/fetch-sqlite3.sh`：从 sqlite.org 下载官方 SQLite amalgamation 到 `thirdparty/sqlite3/`
- `config/`：手写的 tbox 配置（`android/`、`host/`）以及 tbox 源文件列表 `tbox_sources.mk`
- `jni/Android.mk`：ndk-build 构建 `libtbox.a`、`libsqlite3.a` 和 `test`
- `jni/main.c`：调用 `tb_database_sql_init` / `tb_database_sql_open` /
  `tb_database_sql_done` / `tb_database_sql_result_load` 的测试程序
- `tests/host/Makefile`：用同一份代码在 Linux 本机编译并运行

测试内容：打开 `/data/local/tmp/tbox_test.db`（Android）或构建目录下的
`tbox_test.db`（host），建表、插入两行、查询并打印结果，最后输出
`DB CONNECTION TEST: PASS` 或 `FAIL`。

CI（`.github/workflows/build.yml`）：

- `android-build`：用 ndk-build 交叉编译 arm64-v8a / x86_64 的 `test`
- `host-run`：在 Linux 上编译并**实际运行**数据库连接测试
- `emulator-run`：手动触发时（`run-emulator=true`）尝试在模拟器中运行；
  GitHub 托管 runner 通常没有嵌套虚拟化，因此仅作尽力而为

本项目不使用本地编译，编译和运行均通过 GitHub Actions 完成。

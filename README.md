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
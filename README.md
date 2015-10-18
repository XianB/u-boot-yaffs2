# u-boot-yaffs2
本项目目的是在MPC837XERDB(MPC8378ERDB)板子上移植yaffs2到uboot中，此处使用的yaffs2是官网最新版本的代码，支持inband tags(由于我们从618所得到的板子只有512byte + 16byte oob)所以需要支持inband tags，而原先使用的yaffs2版本太低，不支持inband tags，因此最终选用此版本，本项目的实现主要参考

https://forge.tic.eia-fr.ch/git/odroidxu3/u-boot/commits/master/fs/yaffs2  中的过程
https://forge.tic.eia-fr.ch/git/odroidxu3/u-boot/tree/ed77c7770f1613b89659165c3e0dc8a8c5e399d6 以及其中的yaffs2代码

使用的板子源码是板子光盘上的源码，已打补丁，获得方法是./ltib 后，在rpm/BUILD/u-boot-1.3.3中获得

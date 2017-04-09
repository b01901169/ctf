FROM ubuntu:14.04
RUN apt-get update
RUN apt-get install -y gdb nmap
RUN apt-get install -y libc6-i386
RUN apt-get install -y wget xz-utils python-pip python-gevent
RUN cd /opt && wget -qO- https://github.com/BinaryAnalysisPlatform/qira/archive/v1.2.tar.gz | tar zx && cd qira-1.2 && ./install.sh
RUN apt-get -y install gcc-multilib g++-multilib
RUN cd /opt && cd qira-1.2/tracers && ./pin_build.sh
WORKDIR /root
EXPOSE 2000-10000



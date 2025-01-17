FROM registry.docker.com/qt_base:2.0

COPY . /bakeout-qt

WORKDIR bakeout-qt
RUN qmake bakeout-qt.pro
RUN make

ENV QT_XKB_CONFIG_ROOT /usr/share/X11/xkb
ENV DISPLAY :0

RUN systemd-machine-id-setup; chmod 644 /etc/machine-id;
RUN ln -s /root/bin/bakeout-qt /bin/
CMD ["bakeout-qt"]

# docker run --net=host -v /var/lib/dbus/machine-id:/var/lib/dbus/machine-id  registry.docker.com/bakeout-qt
#docker run  -itd --network=host --env DISPLAY=$DISPLAY --env EPICS_CA_ADDR_LIST="10.3.5.11 10.3.5.250"   --privileged --volume="$HOME/.Xauthority:/root/.Xauthority:rw" -v ~/.ssh:/root/.ssh  -v /var/lib/dbus/machine-id:/var/lib/dbus/machine-id -v /tmp/.X11-unix:/tmp/.X11-unix --rm registry.docker.com/bakeout-qt >/dev/null 2>&1


# networkSerial
网络udp调试助手、串口调试、zeromq调试  
后续想想添加多种接口数据发送接收的功能

主要功能：可以创建udp、串口、zeromq发布订阅接口，通过这些接口进行收发数据

发送数据：可以按照int float double 等类型配置发送的数据，并能够设置发送的次数，周期；数据在周期发送时，可以配置数据的变化规律，暂时支持自增，随机，一个crc16
条件发送：可以配置数据发送的条件：当指定的接口接收到数据，且数据指定位置为指定值时，执行数据发送
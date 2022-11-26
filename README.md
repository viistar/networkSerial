# networkSerial
网络udp调试助手、串口调试、zeromq调试  
后续想想添加多种接口数据发送接收的功能

主要功能：可以创建udp、串口、zeromq发布订阅接口，通过这些接口进行收发数据

发送数据：可以按照int float double 等类型配置发送的数据，并能够设置发送的次数，周期；数据在周期发送时，可以配置数据的变化规律，暂时支持自增，随机，一个crc16
条件发送：可以配置数据发送的条件：当指定的接口接收到数据，且数据指定位置为指定值时，执行数据发送
![2022-11-26_175937](https://user-images.githubusercontent.com/24774665/204087397-a9f52e93-fa56-4973-87b7-ed3139488ded.png)
![2022-11-26_180418](https://user-images.githubusercontent.com/24774665/204087415-c1d548c7-12da-4a88-a4b6-9a6761e68f44.png)
![2022-11-26_180654](https://user-images.githubusercontent.com/24774665/204087426-fed1d5ea-a1ef-4df0-a65c-d7770ffcaf3f.png)
![2022-11-26_191436](https://user-images.githubusercontent.com/24774665/204087436-13392c25-93f7-43d5-8344-04e95bad874d.png)

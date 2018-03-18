# 简易通讯协议Hit_Link说明

## 使用范围

DIY的飞控

## 遵循开源协议

本协议为开源项目，项目开发者及其使用者遵循LGPL许可。

## 协议数据结构

协议包示意：

| 0    | 1    | 2    | 3    | 4-(4+n) | 5    | 6    |
| ---- | ---- | ---- | ---- | ------- | ---- | ---- |
| STR  | SEQ  | LEN  | MSG  | PAYLOAD |  CRC  | CRC |


具体内容如下：


|字节(unit_8)序号|内容| 值 | 解释 |
| ---- | ---- | ---- | ---- |
| 0 | (STR)协议包头标志 | v0.0: 0xFE | 新协议包的指标 |
| 1 | (SEQ)包序号 | 0-255 | 包序号，若上一个包为255，下一个归为0 |
| 2 | (LEN)内容数据(Payload)长度 | 0-255 | 关于具体数据(Payload)的长度 |
| 3 | (MSG)数据内容分类编号 | 0-255 | 说明后面的数据的具体含义，用于解包时对数据进行准确的分类和处理 |
| 4 to (4+n) | (PAYLOAD)数据 | (0-255)Bytes | 要发送的数据 |
| n+5 | (CRC)校验位（Checksum High byte） | 0-255 |  |
| n+6 | (CRC)校验位 （Checksum Low byte） | 0-255 |  |

### STR (Start) 数据包头指标

数据包的第一位为STR，值恒为0xFE。当上位机解包时，上一个包结束后，若收到0xFE，则进入解包程序。

### SEQ (Sequence) 包序号 

定义了数据包的序号，便于上位机对数据处理、统计和计算包的丢失率。

飞控启动后，从0开始计数，当包的序号为255时，下一包重新从0开始计数。

### LEN (Length) 数据长度

此位说明数据内容占用字节长度。用于解包时，确认包的结束位置并对Payload作CRC校验。

### MSG (Message) 数据类型编号

说明后面的数据的具体含义，用于解包时对数据进行准确的分类和处理。具体规定如下：

| 值   | 代码      | 内涵    |
| ---- | --------- | ------- |
| 0    | HEARTBEAT | 心跳包  |
| 1    | ATTITUE   | 姿态    |
| 2    | GPS_INT   | GPS数据 |
| ……   | ……        | ……      |

### CEC (Cyclic Redundancy Check) 循环冗余码校验

包的最后两个字节，分别是CRC的高位和低位。CRC算法遵循[ITU X.25](https://www.itu.int/rec/T-REC-X.25-199610-I/en) 和 [SAE AS-4](https://www.sae.org/works/committeeHome.do?comtID=TEAAS4)标准。

Checksum 的具体算法请参考：[Wiki: Checksum](https://en.wikipedia.org/wiki/Checksum)

算法摘要：

1. 先将需要计算checksum数据中的checksum设为0； 
2. 计算checksum的数据按2byte划分开来，每2byte组成一个16bit的值，如果最后有单个byte的数据，补一个byte的0组成2byte； 
3. 将所有的16bit值累加到一个32bit的值中； 
4. 将32bit值的高16bit与低16bit相加到一个新的32bit值中，若新的32bit值大于0Xffff, 再将新值的高16bit与低16bit相加； 
5. 将上一步计算所得的16bit值按位取反，即得到checksum值，存入数据的checksum字段即可

注意：这里的Checksum是对整个包在CRC位之前的所有内容进行校验。也就是CRC校验的起始位是从STR开始的。



## 0 HEARTBEAT 心跳包

心跳包表示飞控正在工作且与地面站建立了联系，或是地面站告知飞控已经建立联系的返回（应答）包。

| 域名          | 数据类型 | 描述                                                         |
| ------------- | -------- | ------------------------------------------------------------ |
| type          | unit8_t  | 飞行器类型/地面站(Quadrotor， Ground Control System and others, defined in HIT_TYPEENUM ) |
| connect_flag  | unit8_t  | 连接状态 (AVALIABLE, UNAVALIABLE, define in HIT_CONNECT_FLAGENUM) |
| system_status | unit8_t  | 系统状态 (Lock, Auto, Stable, etc.  define in HIT_STATEENUM) |
| time_stamp    | unit16_t | 系统时间戳                                                   |
| ……            | ……       | ……                                                           |

## 1 ATTITUTE 姿态数据

姿态数据是飞控向地面站发送飞行器姿态数据。地面站接收后把姿态数据显示在用户界面中。

| 域名        | 数据类型 | 描述         |
| ----------- | -------- | ------------ |
| time_stamp  | unit32_t | 时间戳       |
| roll        | float    | 滚转角       |
| pitch       | float    | 俯仰角       |
| yaw         | float    | 偏航角       |
| roll_speed  | float    | 滚转角速度   |
| pitch_speed | float    | 俯仰角速度   |
| yaw_speed   | float    | 偏航角速度   |



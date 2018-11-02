# CarPlay
  - 不支持rear-seat。
  - 必须支持audio input/output。
  - 后装市场Head Unit必须最小支持6inch的屏幕。

# 26.1 General Requriements
## 26.2.1 Overview
  - 不可以多屏显示。

## 26.2.2 Hardware Requriements
### 26.2.2.1 High Resolution Display
  - 必须支持高分辨率。
  - 不可以缩放。
  - 必须显示所有像素点。
  - 最小分辨率800*480， 24bit of RGB。
  - 最低刷新速率30FPS。
  - square pixels, non-square pixels都要求。

### 26.2.2.2 Processing
   - accessory必须支持Hardware decoding of H.264。

### 26.2.2.3 User Input Devices
  - accessory必须支持touch screen or 旋钮，最低支持选择和返回功能。
  - 如果CarPlay支持的user input(例如：手势识别，旋钮，back button)，
  同时accessory也支持，那么这些user input必须支持给CarPlay。

### 26.2.2.4 Speaker and Microphone
  accessory必须提供audio output和input。

### 26.2.2.5 Siri button
  - accessory必须有一个tactile(可触觉的)button for siri，不可以是soft button。
  - 当CarPlay连接成功后，siri button必须马上并且一直有效
  （**如果车机当前处于一个比较危险的情况下，可以例外**)
  - siri button必须让用户很容易的去操作，推荐设置到steering wheel里面去。
  - 如果车机有自己的voice recognition功能，那么siri button should短押触发本地voice recognition，
  长押触发siri,** 且长押不可以超过600ms **。
  - **当application state = Speech时，代表siri session active**
  - siri session active中，只要用户按下siri button,就必须通知给手机（every time press/release）
  - 如果CarPlay通过无线连接，那么siri button必须也有启动配对的功能，当没有设备连接时，长押siri button,
  accessory必须马上可以被apple device发现。

### 26.2.2.6 "Apple CarPlay" Button
 显示CarPlay UI,accessory必须支持以下一种：
 - A physical button
 - A soft button in a top-level menu
 - A menu item in a top-level menu

 CarPlay session有效的时候，accessory的home or menu必须显示CarPlay icon.
 滑动或者其他用户操作后才显示CarPlay icon,是不允许的。
 CarPlay session无效的时候，CarPlay icon必须disabled or hidden。

### 26.2.2.7 Sensors
 accessory必须提供location information给apple device。

### 26.2.2.8 Connection to the Apple device
### 26.2.2.9 Device Mount Lacation

## 26.2.3 Architecture
 accessory通过ip协议与手机通信，另外accessory必须与apple device建立iAP2连接（授权，认证，交换信息）。

 ![CarPlay Block](/home/wangbo/Documents/carplay/CarPlay笔记/carplayBlock.png)

## 26.2.4 CarPlay over USB
  - accessory最低支持Hi-speed USB
  - 必须支持USB Host MOde transport
  - apple device只要物理连接建立，accessory必须自动建立CarPlay session.
  ![Process for CarPlay session](/home/wangbo/Documents/carplay/CarPlay笔记/ProcessOfCarplaySession.png)

### 26.2.4.1 Role Switch
### 26.2.4.2 iAP2/NCM interface Configuration
 - Role Switch完成之后，accessory必须继续枚举支持的usb interfaces.
 - 必须包含：
    1. iAP2 interface
    2. USB NCM control interface
    3. USB NCM data interface
 - accessory must NOT use the NCM for anything oher than CarPlay。
 - **accessory必须提供Mac address for apple device for use via the CDC Ethernet Networing functional
   descriptor ???**
 - accessory using the USB NCM interface for CarPlay must support at least 100Mbps of bandwidth with
 a latency less than 5ms over both TCP and UDP and a packet loss of less than 1%(muasured with iferf)
 over UDP.

### 26.2.4.3 Authentication
### 26.2.4.4 Networing and Service Discovery
 - 必须是IPv6 link-local address.
 - 必须支持Apple Bonjour

### 26.2.4.5 Session Establishment
 - Connection建立之后，setup and content部分就开始了。
 - accessory在连接carplay上以后，不能发送自动发送play命令。

### 26.2.4.6 Session Termination
 - accessory必须能够检测出断开，并且在500ms以内结束session。
 - **accessory在断开连接时，不能改变audio state.**

## 26.2.5 CarPlay over Wireless
*to be continued*
## 26.2.6 Transitioning Between Wireless and USB
*to be continued*

## 26.2.7 Software Clients
 - accessory必须有iAP2和CarPlay Client
   1. An iAP2 link layer
   2. A CarPlay Communication Plug-in

### 26.2.7.1 iAP2 Client over USB
 作为通过USB连接方式支持CarPlay的accessory,iAP2 Client必须支持：
 - Accessory Authentication
 - Accessory Identification
   - USBHostTransportComponent for wired CarPlay
   - BluetoothTransportComponent and WirelessCarplayTransportComponent for Carplay over Wireless
 - Device Power
 - Lacation information
  - provide location information from **GNSS** and other sensor data.


 iAP2 interface可以传输ios app running in CarPlay的数据信息,比如Music Tel，
这样accessory可以把这些信息显示在一个额外的屏幕上，比如，把电话信息显示在仪表盘上。

accessory可以将车辆的信息以及感应器的信息传递给Apple device,如果accessory支持任何的RangeWaring pareameters,那么accessory在使用carplay navi的时候，不可以通过本体的navi去通知用户加油或者充电。

### 26.2.7.2 iAP2 Client over Bluttooth

### 26.2.7.3 CarPlay Client
 - carplay Client负责根据Resource Manager来共享与车机的资源。
 - carplay Client负责user event,传输画面和声音。
 - Accessory must provide Networing stack that support multiple concurrent UDP and TCP channels for:
    - audio/video transfer
    - command and control
    - clock synchronization and retransmission

### 26.2.7.4 iAP2 Client over

### 26.2.7.5 IOS applications for CarPlay
如果accessory支持ios applications for CarPlay,那么accessory必须设置(至少一次)SupportedExternalAccessoryProtocol pareameters in their IdentificationInformation message。

## 26.2.8 Media Types and Formats

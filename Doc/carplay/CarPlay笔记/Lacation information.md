# 35 Lacation information

## 35.1 Requriements
 Accessory support the location via iAP2 must send or receive the following
 iAP2 control session message:
  - StartLocationInformation
  - LocationInformation
  - StopLocationInformation

  Accessory support the location via iAP2 may also send or receive the following
  iAP2 control session message:
  - GPRMCDataStatusValuesNotification

  Accessory must porvide location information to Apple device by sending NMEA
  sentences based on their positioning hardware:
  - Global Navigation Satellite System(GNSS) Receiver
  - Speed Sensors

### 35.1.1 Global Navigation Satellite System(GNSS) Receiver
Accessory that have NGSS receiver must provide:
  - GPGGA（一帧GPS定位数据）
  - GPRMC(推荐定位信息)
GNSS Receiver必须支持GPS和GLONASS

### 35.1.2 Speed
Accessory have speed Sensors should provide
- PASCD

**CarPlay accessory必须提供PASCD**

### 35.1.3 NMEA Sentence Fields

## 35.2 Usage
- Accessory必须在Accessory Identification里列举出支持的location information type。
- 当Accessory被识别成功后，Apple device已经准备好接收location information时，Apple device
  会发送StartLocationInformation给Accessory
- Accessory收到StartLocationInformation后，发送LocationInformation.
-Apple device不再需要external location时，它会发送StartLocationInformation,
 Accessory接收到后，必须停止发送LocationInformation.

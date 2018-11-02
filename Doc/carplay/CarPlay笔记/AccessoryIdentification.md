# 16 Accessory Identification
## 16.1 Requirements
control session version 2允许Apple device来选择Identification和Authentication的顺序。
否则，必须Accessory Authentication先完成，再继续Accessory Identification.

## 16.2 Usage
- 所有支持Accessory Identification的设备（control session version 2)必须通过iAP2发送或者接受以下消息：
  1. StartIdentification
  2. IdentificationInformation
  3. IdentificationAccepted
  4. IdentificationRejected
  5. Cancelldentification
  6. IdentificationInformation

- Apple device发起StartIdentification, Accessory回复IdentificationInformation
- Apple device会评估IdentificationInformation，
  - 成功回复IdentificationAccepted
  - 失败回复IdentificationRejected
    如果失败accessory必须send another IdentificationInformation,或者
    发送Cancelldentification来结束Identification过程，此时Apple device会通知用户
    **accessory is not supported**

### 16.2.1 Manufacturing information
 Manufacturing information是IdentificationInformation的参数。
 包括：
  - Name
  - ModelIdentifier
  - Manufacture
  - SerialNumber
  - FirmwareVersion(必须唯一)
  - HardwareVersion(必须唯一)

### 16.2.2 Send/Received iAP2 control Session Messages
### 16.2.3 Power Capabilities
Accessory必须提供PowerProvidingCapability和MaximumCurrentDrawnFromDevice parameters
in IdentificationInformation.
- 如果Accessory不给Apple device提供电量，PowerProvidingCapability must set to 0
- 如果Accessory吸取Apple device电量，MaximumCurrentDrawnFromDevice must set to 0

### 16.2.4 iAP2 Transport Components
 Accessory必须声明至少一种transport Component.

### 16.2.4 Additional Parameters

## 16.3 Examples
![Accessory Identification](/home/wangbo/Documents/carplay/CarPlay笔记/Identification_1.png)
![Accessory Identification](/home/wangbo/Documents/carplay/CarPlay笔记/Identification_2.png)

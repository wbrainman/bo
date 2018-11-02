# Accessory Authentication

## 15.1 Requirements
 - Accessory硬件必须有Apple Authentication 3.0 Coprocessor或者Apple Authentication Coprocessor 2.0C
 - 一个Accessory可以利用一个Apple Authentication processor去认证多个Apple device,但是多个Accessory
   不可以用一个Apple Authentication processor去认证同一个Apple device。
 - Accessory必须支持iAP2
 - when using control session version 2, the Authentication messages must be included in the
  **IdentificationInformation**
 - 所有支持Accessory Authentication的设备（control session version 2)必须通过iAP2发送或者接受以下消息：
   1. RequestAuthenticationCertificate
   2. AuthenticationCertificate
   3. RequestAuthenticationChallengeResponse
   4. AuthenticationResponse
   5. AuthenticationFailed
   6. AccessoryAuthenticationSerialNumber

## 15.2 Usage
  Accessory Authentication流程图：
  ![Accessory Authentication](/home/wangbo/Documents/carplay/CarPlay笔记/AccessoryAuthentication.png)

  - **RequestAuthenticationChallengeResponse to AuthenticationResponse MUST be in 2s**

/**
  ******************************************************************************
  * @file    usbd_hid.h
  * @author  MCD Application Team
  * @version V2.4.2
  * @date    11-December-2015
  * @brief   Header file for the usbd_hid_core.c file.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2015 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software
  * distributed under the License is distributed on an "AS IS" BASIS,
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USB_HID_H
#define __USB_HID_H

#ifdef __cplusplus
extern "C" {
#endif

    /* Includes ------------------------------------------------------------------*/
#include  "usbd_ioreq.h"

#define HID_EPIN_ADDR                 0x81
#define HID_EPIN_SIZE                 0x0a

#define HID_EPOUT_ADDR                0x01
#define HID_EPOUT_SIZE                0x40

#define USB_HID_CONFIG_DESC_SIZ       41
#define USB_HID_DESC_SIZ              9
#define HID_JOY_REPORT_DESC_SIZE     100

#define HID_DESCRIPTOR_TYPE           0x21
#define HID_REPORT_DESC               0x22

#define HID_HS_BINTERVAL              0x01
#define HID_FS_BINTERVAL              0x01
#define HID_POLLING_INTERVAL          0x01

#define HID_REQ_SET_PROTOCOL          0x0B
#define HID_REQ_GET_PROTOCOL          0x03

#define HID_REQ_SET_IDLE              0x0A
#define HID_REQ_GET_IDLE              0x02

#define HID_REQ_SET_REPORT            0x09
#define HID_REQ_GET_REPORT            0x01

typedef enum
{
    HID_IDLE = 0,
    HID_BUSY,
}
HID_StateTypeDef;


__ALIGN_BEGIN typedef struct
{
    uint32_t             Protocol;
    uint32_t             IdleState;
    uint32_t             AltSetting;

    uint8_t              HIDRxBuffer[HID_EPOUT_SIZE];
    uint32_t             HIDRxLength;

    uint8_t              IsReportAvailable;

    HID_StateTypeDef     state;
}
USBD_HID_HandleTypeDef __ALIGN_END;

extern unsigned short x_low_th;
extern unsigned short y_low_th;
extern unsigned short x_high_th;
extern unsigned short y_high_th;

extern unsigned short report2send;
extern unsigned short shifter;

extern USBD_ClassTypeDef  USBD_HID;
#define USBD_HID_CLASS    &USBD_HID

uint8_t USBD_HID_SendReport(USBD_HandleTypeDef *pdev, uint8_t *report, uint16_t len);
uint32_t USBD_HID_GetPollingInterval(USBD_HandleTypeDef *pdev);

#ifdef __cplusplus
}
#endif

#endif  /* __USB_HID_H */

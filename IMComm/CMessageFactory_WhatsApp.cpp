#include "stdafx.h"
#include "structsAndConstants.h"
#include "structsAndConstants.cpp"
#include "../GenComm/IMessage.h"
#include "../GenComm/IMessageFactory.h"
#include "MGroupCreateUpdate.h"
#include "MAcknowledgeMessage.h"
#include "MTextMessage.h"

#include "CMessageFactory_WhatsApp.h"


CMessageFactory_WhatsApp::CMessageFactory_WhatsApp()
{
}


CMessageFactory_WhatsApp::~CMessageFactory_WhatsApp()
{
}

// Returns message object
IMessage* CMessageFactory_WhatsApp::CreateMessage(int type)
{
	switch (((EMessageType)type))
	{
	/*case EMessageType::ACKNOWLEDGE:
		return new MAcknowledgeMessage;
	case EMessageType::CREATE_UPDATE_GROUP:
		return new MGroupCreateUpdate;
	default:*/
		 case EMessageType::TEXT_MESSAGE:
		return new MTextMessage;
	}
}
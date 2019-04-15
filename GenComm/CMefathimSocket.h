#pragma once
#include <map>
#include "IMessageFactory.h"
#include "IMessage.h"
#ifdef DLL_IMPORT
#define DLL __declspec(dllimport)
#else
#define DLL __declspec(dllexport)
#endif

#include <list>

class CMefathimSocket : public CAsyncSocket
{
	// For server side usage only:
	std::list<CMefathimSocket*> m_listSocketsToClient;
	std::string m_sSocketName;
protected:
	std::map<int, void*> m_hashCallbacks; // TODO: Change value to vector/list of function pointers
	IMessageFactory* m_pMessageFactory;
public:
	CMefathimSocket(IMessageFactory* pMessageFactory, std::string sSocketName);
	~CMefathimSocket();

	void RegisterCallback(int eMessageType, void(*pfnCallback)(IMessage*));
	void RemoveCallback(int eMessageType);
	void OnMessageReceived(char* pBuffer);

	virtual void OnConnect(int nErrorCode);
	virtual void OnAccept(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	virtual void OnClose(int nErrorCode);
};
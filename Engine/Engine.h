#pragma once

#include "Device.h"
#include "CommandQueue.h"
#include "SwapChain.h"
#include "RootSignature.h"
#include "Mesh.h"
#include "Shader.h"
#include "ConstantBuffer.h"
#include "TableDescriptorHeap.h"
#include "Texture.h"
#include "DepthStencilBuffer.h"

#include "Input.h"
#include "Timer.h"

class Engine
{
public:

	void Init(const WindowInfo& info);
	void Render();

public:	
	void Update();

public:
	shared_ptr<Device> GetDevice() { return _device; }
	shared_ptr<CommandQueue> GetCmdQueue() { return _cmdQueue; }
	shared_ptr<SwapChain> GetSwapChain() { return _swapChain; }
	shared_ptr<RootSignature> GetRootSignature() { return _rootSignature; }
	shared_ptr<ConstantBuffer> GetCB() { return _cb; }
	shared_ptr<TableDescriptorHeap> GetTableDescHeap() { return _tableDescHeap; }
	shared_ptr<DepthStencilBuffer> GetDepthStencilBuffer() { return _depthStencilBuffer; }

	shared_ptr<Input> GetInput() { return _input; }
	shared_ptr<Timer> GetTimer() { return _timer; }

public:
	void RenderBegin();
	void RenderEnd();

	void ResizeWindow(int32 width, int32 height);

private:
	void ShowFps();

private:
	// 그려질 화면 크기 관련
	WindowInfo		_window;
	D3D12_VIEWPORT	_viewport = {};
	D3D12_RECT		_scissorRect = {};

	// 우리가 GPU에 접근을 하거나, 리소스를 요청을 하거나 할 때 사용하는 인력사무소 대표 (즉, device를 통해 GPU에 접근, 가장 핵심)
	shared_ptr<Device> _device = make_shared<Device>();

	// GPU에 요청할때, 한번 한번 보내는것이 아니라 뭉쳐서 한번에 보내기위한 수단
	shared_ptr<CommandQueue> _cmdQueue = make_shared<CommandQueue>();

	// 더블 버퍼(종이 두 장), 한 장은 GPU가 그리는 용도, 한 장은 화면에 출력하는 용도. 계속 둘이 왔다갔다
	shared_ptr<SwapChain> _swapChain = make_shared<SwapChain>();

	// 리소스를 서술하는 용도(기안서) (= View라고도 한다.)
	// DH [ [View] [View] ] -> [ Resource ]
	// DH안에 있는 각자의  View는 각자의 리소스를 설명하고 있다.
	// (현재, DH를 SwapChain 안에서 구현하기 때문에 주석처리.)
	// shared_ptr<class DescriptorHeap> _descHeap;

	// GPU의 레지스터 장소를 임대하는 것. (임대계약서만 싸인)
	shared_ptr<RootSignature> _rootSignature = make_shared<RootSignature>();


	shared_ptr<ConstantBuffer> _cb = make_shared<ConstantBuffer>();

	shared_ptr<TableDescriptorHeap> _tableDescHeap = make_shared<TableDescriptorHeap>();

	shared_ptr<DepthStencilBuffer> _depthStencilBuffer = make_shared<DepthStencilBuffer>();

	shared_ptr<Input> _input = make_shared<Input>();
	shared_ptr<Timer> _timer = make_shared<Timer>();
};


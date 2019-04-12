#include "stdafx.h"
#include "engine.h"

Engine::Engine()
{
	context = new Context();
	graphics = context->RegisterSubsystem<Graphics>(); 

	context->Intialize(); //Graphics�� Intialize�� �ҷ�����

	//===========================// ���� �и�����
	//���� �⺻ ������ �ﰢ��
	/* ��� ����  0-1-2
			1	
	
		0	2
	*/

	//Create VerTex Data
	{
		vertices = new VertexColor[3]; //�迭�̱⶧���� DELETE_ARRAY
		vertices[0].position = D3DXVECTOR3{ -0.5f,-0.5f,0.0f };
		vertices[0].color = D3DXCOLOR{ 1.0f,0.0f,0.0f,1.0f }; //���������������ϱ� a���� 1

		vertices[1].position = D3DXVECTOR3{ +0.5f,+0.5f,0.0f };
		vertices[1].color = D3DXCOLOR{ 1.0f,1.0f,0.0f,1.0f }; //���������������ϱ� a���� 1

		vertices[2].position = D3DXVECTOR3{ +0.5f,-0.5f,0.0f };
		vertices[2].color = D3DXCOLOR{ 0.0f,0.0f,1.0f,1.0f }; //���������������ϱ� a���� 1

	}

	//Create Vertex Buffer //COM�� DESC�� �ʼ�
	{
		D3D11_BUFFER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D10_BUFFER_DESC));
		//buffer�� ����ҹ�� DEFAULT�� CPU���� ���ٺҰ� GPU���� �а��� ����
		desc.Usage = D3D11_USAGE_DEFAULT;
		//BindFlags ���̶��� ��� �������ΰ� 
		//VERTEX_BUFFER���·� �������̴�
		desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		//Byte�� ũ�� ��ŭ ����Ұ��� VertexColor�� 3�踸ŭ (������ ����Ѱ��� 3��)
		desc.ByteWidth = sizeof(VertexColor) * 3;

		D3D11_SUBRESOURCE_DATA subData; // ������ ���� �������ְ� (Create VerTex Data) ���۸�����
		ZeroMemory(&subData, sizeof(D3D10_SUBRESOURCE_DATA));
		subData.pSysMem = vertices; //�ּҸ� ������Ǳ⿡ vertices��ü�� ����

		HRESULT hr = graphics->GetDevice()->CreateBuffer
		(
			&desc,
			&subData,
			&vertexBuffer
		);
		assert(SUCCEEDED(hr));
	}


}

Engine::~Engine()
{
	SAFE_DELETE_ARRAY(vertices);
	SAFE_DELETE(context);
}

void Engine::Update()
{

}

void Engine::Render()
{
	//auto graphics = context->GetSubsystem<Graphics>();
	graphics->BeginScene();
	{

	}
	graphics->EndScene();
}

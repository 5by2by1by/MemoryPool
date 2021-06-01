#pragma once

#include "Common.h"

class ThreadCache{
	private:
		Freelist _freelist[NLISTS];//������������184��FreeList����

	public:
		//������ͷ��ڴ����
		void* Allocate(size_t size);
		void Deallocate(void* ptr, size_t size);

		//�����Ļ����ȡ����
		void* FetchFromCentralCache(size_t index, size_t size);

		//�ͷŶ���ʱ����������ʱ�������ڴ�ص����Ķ�
		void ListTooLong(Freelist* list, size_t size);
};

//��̬�ģ��������пɼ�
//ÿ���߳��и��Լ���ָ��, ��(_declspec (thread))��������ʹ��ʱ��ÿ���������Լ��ģ��Ͳ��ü�����
//ÿ���̶߳����Լ���tlslist
_declspec (thread) static ThreadCache* tlslist = nullptr;
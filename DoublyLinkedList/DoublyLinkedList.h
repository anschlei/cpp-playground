#pragma once
#include <iostream>

namespace
{
	template <typename T>
	struct SNode
	{
		T*		m_pData = nullptr;
		SNode*  m_pPre  = nullptr;
		SNode*  m_pSuc  = nullptr;
	};
}

namespace List
{
	template <typename T>
	class CDoublyLinkedList
	{
		using X			= T;
		using XPtr		= X*;
		using Node		= SNode<X>;
		using NodePtr	= Node*;

	public:
		CDoublyLinkedList	();
		~CDoublyLinkedList	();

	public:
		void PushBack	(XPtr _pNewData);
		void PushFront	(XPtr _pNewData);

		bool InsertAtIndex		(size_t _Index, XPtr _pNewData);
		XPtr GetNodeAtIndex		(size_t _Index);
		void RemoveNodeAtIndex	(size_t _Index);

		XPtr PopBack  ();
		XPtr PopFront ();

	private:
		NodePtr m_pStartNode;
		NodePtr m_pEndNode;
		size_t	m_Size;
	};

}//namespace List


namespace List
{
	template<typename T>
	CDoublyLinkedList<T>::CDoublyLinkedList()
		: m_pStartNode	(nullptr)
		, m_pEndNode	(nullptr)
		, m_Size		(0)
	{}

	template<typename T>
	CDoublyLinkedList<T>::~CDoublyLinkedList()
	{
		while (m_Size > 0)
		{			
			if (m_Size > 1)
			{
				m_pEndNode = m_pEndNode->m_pPre;

				delete m_pEndNode->m_pSuc;
			}
			else
			{
				delete m_pEndNode;

				m_pStartNode = nullptr;

				m_pEndNode	 = nullptr;
			}

			--m_Size;
		}
	}

	template <typename T>
	void CDoublyLinkedList<T>::PushBack(XPtr _pNewData)
	{
		NodePtr pNewNode = new Node;

		pNewNode->m_pData = _pNewData;

		if (m_Size > 0)
		{
			m_pEndNode->m_pSuc = pNewNode;

			pNewNode->m_pPre = m_pEndNode;

			pNewNode->m_pSuc = nullptr;

			m_pEndNode		 = pNewNode;
		}
		else // first element
		{
			pNewNode->m_pPre	 = m_pStartNode;

			pNewNode->m_pSuc	 = m_pEndNode;

			m_pEndNode			 = pNewNode;
								 
			m_pStartNode		 = pNewNode;
								 
			m_pEndNode->m_pSuc	 = nullptr;
		}

		++m_Size;
	}

	template<typename T>
	void CDoublyLinkedList<T>::PushFront(XPtr _pNewData)
	{
		NodePtr pNewNode = new Node;

		pNewNode->m_pData = _pNewData;

		if (m_Size > 0)
		{
			pNewNode->m_pPre			 = m_pStartNode->m_pPre;

			pNewNode->m_pSuc			 = m_pStartNode;
			
			m_pStartNode				 = pNewNode;
			
			m_pStartNode->m_pSuc->m_pPre = pNewNode;
		}
		else // first element
		{
			pNewNode->m_pPre	 = m_pStartNode;

			pNewNode->m_pSuc	 = m_pEndNode;

			m_pEndNode			 = pNewNode;

			m_pStartNode		 = pNewNode;

			m_pEndNode->m_pSuc	 = nullptr;

			m_pStartNode->m_pPre = nullptr;
		}

		++m_Size;
	}

	//TOPDO
	template<typename T>
	bool CDoublyLinkedList<T>::InsertAtIndex(size_t _Index, XPtr _pNewData)
	{
		NodePtr pSearchNode = m_pStartNode;
		NodePtr pNewNode	= new Node;

		pNewNode->m_pData = _pNewData;

		if (_Index > m_Size) return false;

		if (m_Size == 0) // insert at the start as init element
		{
			pNewNode->m_pSuc	= m_pEndNode;

			pNewNode->m_pPre	= m_pStartNode;

			m_pStartNode		= pNewNode;
			
			m_pEndNode			= pNewNode;
			
			++m_Size;
		}
		else if (_Index == 0) // insert at the begin
		{
			pNewNode->m_pSuc		= m_pStartNode;

			pNewNode->m_pPre		= nullptr;

			m_pStartNode->m_pPre	= pNewNode;

			m_pStartNode			= pNewNode;

			++m_Size;
		}
		else if (_Index == m_Size) // insert at the end
		{
			pNewNode->m_pPre			= m_pEndNode;

			m_pEndNode->m_pPre->m_pSuc	= pNewNode;

			m_pEndNode					= pNewNode;

			pNewNode->m_pSuc			= nullptr;

			++m_Size;
		}
		else
		{
			//search begin at start
			for (size_t index = 1; index < _Index; ++index)
			{
				pSearchNode = pSearchNode->m_pSuc;
			}

			//@todo search begin at end

			pNewNode->m_pPre = pSearchNode;

			pNewNode->m_pSuc = pSearchNode->m_pSuc;

			pSearchNode->m_pSuc->m_pPre = pNewNode;

			pSearchNode->m_pSuc			= pNewNode;

			++m_Size;
		}

		return true;
	}

	template<typename T>
	T* CDoublyLinkedList<T>::GetNodeAtIndex(size_t _Index)
	{
	}

	template<typename T>
	void CDoublyLinkedList<T>::RemoveNodeAtIndex(size_t _Index)
	{
	}
	
	template<typename T>
	T* CDoublyLinkedList<T>::PopBack()
	{
		if (m_Size > 0)
		{
			T* pReturnValue		= m_pEndNode->m_pData;
			
			m_pEndNode			= m_pEndNode->m_pPre;

			delete m_pEndNode->m_pSuc;

			--m_Size;

			m_pEndNode->m_pSuc	= nullptr;	

			return pReturnValue;
		}
		else // list is empty
		{
			return nullptr;
		}
	}

	template<typename T>
	T* CDoublyLinkedList<T>::PopFront()
	{
		if (m_Size > 0)
		{
			T* pReturnValue		= m_pStartNode->m_pData;

			m_pStartNode		= m_pStartNode->m_pSuc;

			delete m_pStartNode->m_pPre;

			--m_Size;

			m_pStartNode->m_pPre = nullptr;

			return pReturnValue;
		}
		else // list is empty
		{
			return nullptr;
		}
	}

}//namespace List
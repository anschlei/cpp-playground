/**
* 	@Autor	: Andy Schleising 
*	@Date	: 08.03.2023
*
*	@Description
*	Template Class DoublyLinkedList.
*/

#pragma once

//----------------------------------------------------------------------------------
//					*Classes*
//----------------------------------------------------------------------------------

namespace
{
	/**
	* Template SNode
	* @property T*	    m_pData	: included  a pointer to the saved type/class
	* @property SNode*  m_pPre	: previous pointer to the SNode bevor
	* @property SNode*  m_pSuc	: successor pointer to the SNode after
	*/
	template <typename T>
	struct SNode
	{
		T*	m_pData = nullptr;
		SNode*  m_pPre  = nullptr;
		SNode*  m_pSuc  = nullptr;
	};
}

namespace List
{
	/**
	* Template CDoublyLinkedList
	* @property NodePtr m_pStartNode	: hold the first element or nullptr
	* @property NodePtr m_pEndNode		: hold the last element or nullptr
	* @property size_t  m_Size		: hold the current size of the list
	*/
	template <typename T>
	class CDoublyLinkedList
	{
		using X			= T;
		using XPtr		= X*;
		using Node		= SNode<X>;
		using NodePtr		= Node*;

	public:
		CDoublyLinkedList	();
		~CDoublyLinkedList	();

	public:
		void PushBack	(XPtr _pNewData);
		void PushFront	(XPtr _pNewData);

		bool InsertAtIndex	(size_t _Index, XPtr _pNewData);
		XPtr At			(size_t _Index);
		bool RemoveAt		(size_t _Index);
		size_t Size();

		XPtr PopBack  ();
		XPtr PopFront ();

		XPtr operator[](size_t _Index);

	private:
		NodePtr m_pStartNode;
		NodePtr m_pEndNode;
		size_t	m_Size;
	};

}//namespace List


//----------------------------------------------------------------------------------
//				*Template Class Functions*
//----------------------------------------------------------------------------------

namespace List
{
	/**
	* Constructor, set all member variables to default values.
	*/
	template<typename T>
	CDoublyLinkedList<T>::CDoublyLinkedList()
		: m_pStartNode	(nullptr)
		, m_pEndNode	(nullptr)
		, m_Size	(0)
	{}

	/**
	* Destructor, delete all new created SNodes beginning from the end.
	*/
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

				m_pStartNode 	= nullptr;

				m_pEndNode	= nullptr;
			}

			--m_Size;
		}
	}

	/**
	* Add a new element at the end.
	* @property XPtr _pNewDta: a pointer from the storage object T
	*/
	template <typename T>
	void CDoublyLinkedList<T>::PushBack(XPtr _pNewData)
	{
		NodePtr pNewNode  = new Node;

		pNewNode->m_pData = _pNewData;

		if (m_Size > 0)
		{
			m_pEndNode->m_pSuc 	= pNewNode;

			pNewNode->m_pPre   	= m_pEndNode;

			pNewNode->m_pSuc   	= nullptr;

			m_pEndNode		= pNewNode;
		}
		else // first element
		{
			pNewNode->m_pPre	 = m_pStartNode;

			pNewNode->m_pSuc	 = m_pEndNode;

			m_pEndNode		 = pNewNode;
								 
			m_pStartNode		 = pNewNode;
								 
			m_pEndNode->m_pSuc	 = nullptr;
		}

		++m_Size;
	}

	/**
	* Add a new element at the begin.
	* @property XPtr _pNewDta: a pointer from the storage object T
	*/
	template<typename T>
	void CDoublyLinkedList<T>::PushFront(XPtr _pNewData)
	{
		NodePtr pNewNode  = new Node;

		pNewNode->m_pData = _pNewData;

		if (m_Size > 0)
		{
			pNewNode->m_pPre		= m_pStartNode->m_pPre;

			pNewNode->m_pSuc		= m_pStartNode;
			
			m_pStartNode			= pNewNode;
			
			m_pStartNode->m_pSuc->m_pPre 	= pNewNode;
		}
		else // first element
		{
			pNewNode->m_pPre	= m_pStartNode;

			pNewNode->m_pSuc	= m_pEndNode;

			m_pEndNode		= pNewNode;

			m_pStartNode		= pNewNode;

			m_pEndNode->m_pSuc	= nullptr;

			m_pStartNode->m_pPre 	= nullptr;
		}

		++m_Size;
	}

	/**
	* Insert a new element between the index pre and suc SNode*.
	* @property size_t _Index
	* @property XPtr _pNewData	: a pointer from the storage object T
	* @return bool			: if insert at index in range of the list size
	*/
	template<typename T>
	bool CDoublyLinkedList<T>::InsertAtIndex(size_t _Index, XPtr _pNewData)
	{
		NodePtr pSearchNode 	= m_pStartNode;
		NodePtr pNewNode	= new Node;

		pNewNode->m_pData 	= _pNewData;

		if (_Index > m_Size) return false;

		if (m_Size > 0 && m_Size != _Index && _Index > 0) //insert between
		{
			//search begin at start
			for (size_t index = 1; index < _Index; ++index)
			{
				pSearchNode = pSearchNode->m_pSuc;
			}

			pNewNode->m_pPre 		= pSearchNode;

			pNewNode->m_pSuc 		= pSearchNode->m_pSuc;

			pSearchNode->m_pSuc->m_pPre 	= pNewNode;

			pSearchNode->m_pSuc 		= pNewNode;

			++m_Size;
		}
		else if (m_Size == 0) // insert at the start as init element
		{
			pNewNode->m_pSuc	= m_pEndNode;

			pNewNode->m_pPre	= m_pStartNode;

			m_pStartNode		= pNewNode;
			
			m_pEndNode		= pNewNode;
			
			++m_Size;
		}
		else if (_Index == 0) // insert at the begin
		{
			pNewNode->m_pSuc	= m_pStartNode;

			pNewNode->m_pPre	= nullptr;

			m_pStartNode->m_pPre	= pNewNode;

			m_pStartNode		= pNewNode;

			++m_Size;
		}
		else if (_Index+1 == m_Size) // insert at the end
		{
			pNewNode->m_pPre		= m_pEndNode;

			m_pEndNode->m_pPre->m_pSuc	= pNewNode;

			m_pEndNode			= pNewNode;

			pNewNode->m_pSuc		= nullptr;

			++m_Size;
		}

		return true;
	}

	/**
	* Gets the element from the index.
	* @property size_t _Index	: gest the SNode-Data from the index
	* @return T* SNode->m_pData 	: holds a pointer to the storage object
	*/
	template<typename T>
	T* CDoublyLinkedList<T>::At(size_t _Index)
	{
		if (_Index > m_Size) return nullptr;

		NodePtr pNewNode = m_pStartNode;

		//search beginn at start
		for (size_t index = 0; index < _Index; ++index)
		{
			pNewNode = pNewNode->m_pSuc;
		}

		return pNewNode->m_pData;
	}

	/**
	* Remove the element at the index.
	* @property size_t _Index	: holds the target index
	* @return bool			: if the element exist and was deleted returns true
	*/
	template<typename T>
	bool CDoublyLinkedList<T>::RemoveAt(size_t _Index)
	{
		NodePtr pRemoveNode = m_pStartNode;

		if(_Index > m_Size) return false;

		for (size_t index = 0; index < _Index; ++index)
		{
			pRemoveNode = pRemoveNode->m_pSuc;
		}

		if (_Index == 0 && m_Size > 1) // start
		{
			pRemoveNode->m_pSuc->m_pPre = m_pStartNode;

			m_pStartNode = pRemoveNode->m_pSuc;
		}
		else if (_Index+1 == m_Size ) // end
		{
			m_pEndNode = nullptr;
		}
		else if (m_Size == 1) // last element
		{
			m_pStartNode 	= nullptr;

			m_pEndNode 	= nullptr;
		}
		else // other elements
		{
			pRemoveNode->m_pPre->m_pSuc = pRemoveNode->m_pSuc;
			pRemoveNode->m_pSuc->m_pPre = pRemoveNode->m_pPre;
		}

		delete pRemoveNode;

		--m_Size;

		return true;
	}

	template<typename T>
	size_t CDoublyLinkedList<T>::Size()
	{
		return m_Size;
	}

	/**
	* Get the latest element and remove it.
	* @return T* pReturnValue : if the the list was not empty otherwise gets a nullptr
	*/
	template<typename T>
	T* CDoublyLinkedList<T>::PopBack()
	{
		if (m_Size > 0 && m_Size != 1)
		{
			T* pReturnValue		= m_pEndNode->m_pData;
			
			m_pEndNode		= m_pEndNode->m_pPre;

			delete m_pEndNode->m_pSuc;

			--m_Size;

			m_pEndNode->m_pSuc	= nullptr;	

			return pReturnValue;
		}
		else if (m_Size == 1)
		{
			T* pReturnValue = m_pEndNode->m_pData;

			m_pEndNode 	= m_pEndNode->m_pPre;

			delete m_pEndNode;

			--m_Size;

			m_pEndNode = nullptr;

			return pReturnValue;
		}
		else // list is empty
		{
			return nullptr;
		}
	}

	/**
	* Get the first element and remove it.
	* @return T* pReturnValue : if the the list was not empty otherwise gets a nullptr
	*/
	template<typename T>
	T* CDoublyLinkedList<T>::PopFront()
	{
		if (m_Size > 0 && m_Size != 1)
		{
			T* pReturnValue		= m_pStartNode->m_pData;

			m_pStartNode		= m_pStartNode->m_pSuc;

			delete m_pStartNode->m_pPre;

			--m_Size;

			m_pStartNode->m_pPre = nullptr;

			return pReturnValue;
		}
		else if (m_Size == 1)
		{
			T* pReturnValue = m_pStartNode->m_pData;

			m_pStartNode 	= m_pStartNode->m_pSuc;

			delete m_pStartNode;

			--m_Size;

			m_pStartNode = nullptr;

			return pReturnValue;
		}
		else // list is empty
		{
			return nullptr;
		}
	}

	/**
	* Operator overloading [], with the same function as At function.
	* @property size_t _Index	: hold the target index
	* @return T* SNode->m_pData 	: holds a pointer to the storage object
	*/
	template<typename T>
	T* CDoublyLinkedList<T>::operator[](size_t _Index)
	{
		return CDoublyLinkedList::At(_Index);
	}

}//namespace List

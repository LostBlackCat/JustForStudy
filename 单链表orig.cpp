//µ¥Á´±íorig¡£cpp
template<class Type>
class Node
{
public:
	constexpr Node(Type elem, Node* next = nullptr)noexcept : m_data(move(elem)), m_pnext(next) {}
	~Node() noexcept
	{
		delete m_pnext;
	}
	Type m_data;
	Node* m_pnext;
};

template<class Type>
class ForwardList
{
public:
	constexpr ForwardList() noexcept : m_pfirst(nullptr) {}
	~ForwardList() noexcept
	{
		delete m_pfirst;
	}
	constexpr Node<Type>* Begin() noexcept
	{
		return m_pfirst;
	}
	void PushFront(Type data)
	{
		m_pfirst = new Node<Type>(move(data), m_pfirst);
	}
	void PopFront()
	{
		Node<Type>* temp = m_pfirst;
		m_pfirst = m_pfirst->m_pnext;
		temp->m_pnext = nullptr;
		delete temp;
	}
	void Insert(const Node<Type>* pos, Node<Type>* node) noexcept
	{
		node->m_pnext = pos->m_pnext;
		pos->m_pnext = node;
	}
	void Insert(const Node<Type>* pos, Type data)
	{
		Insert(pos, new Node<Type>(move(data));
	}
	void Delete(const Node<Type>* prev)
	{
		Node<Type>* temp = prev->m_pnext;
		prev->m_pnext = prev->m_pnext->m_pnext;
		temp->m_pnext = nullptr;
		delete temp;
	}
private:
	Node<Type>* m_pfirst;
};
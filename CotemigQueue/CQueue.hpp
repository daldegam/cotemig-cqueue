namespace Cotemig
{
    namespace Queue
    {
		/*!
		 * \class	CQueue
		 *
		 * \brief	Classe de fila de n�meros float com implementa��o de ponteiros
		 *
		 * \date March 2017
		 */
        class CQueue
        {
            private:
				/*!
				 * \brief	Marca o objeto CQueue como copia
				 *
				 * \note	Utilizado no destrutor da classe para liberar
				 *			a memoria alocada para a fila
				 */
				bool m_bCopy;

				/*!
				 * \brief	Coloca a classe em modo debug (imprime mensagens de debug)
				 */
                int m_bDebug;

				/*!
				 * \brief	Tamanho m�ximo da fila
				 */
                int m_iMaxSize;
				
				/*!
				 * \brief	Posi��o inicial da fila
				 */
                int m_iBegin;

				/*!
				 * \brief	Posi��o final da fila
				 */
                int m_iEnd;
				
				/*!
				 * \brief	Ponteiro com os valores float
				 *
				 * \note	Array de m_iMaxSize
				 */
                float * p_fItems;

            public:
				/*!
				 * \brief	Construtor da classe de fila
				 *
				 * \param	size	Tamanho da fila
				 */
				CQueue(int size);
				CQueue(const CQueue &queue);
				
				/*!
				 * \brief	Destrutor da classe de fila
				 */
                virtual ~CQueue();

				
				/*!
				 * \brief	Obtem a posi��o atual a ser lida na fila
				 *
				 * \return	Valor atual da posi��o na fila
				 */
                int GetBeginPosition();
				
				/*!
				 * \brief	Insere um item na fila
				 *
				 * \param	item	Valor a ser inserido
				 */
                void Insert(float item);
				
				/*!
				 * \brief	Remove um elemento da fila
				 *
				 * \return	Valor armazenado na fila
				 */
                float Remove();
				
				/*!
				 * \brief	Verifica se a fila est� vazia
				 *
				 * \return	True para vazio, False para quando exitir elementos na lista
				 */
                bool IsEmpty();
				
				/*!
				 * \brief	Verifica se a fila est� cheia
				 *
				 * \return	True para cheia, False para vazia ou parcialmente cheia
				 */
                bool IsFull();
				
				/*!
				 * \brief	Obtem o tamanho atual da fila
				 *
				 * \return	Tamanho atual da fila
				 */
                int Size();
				
				/*!
				 * \brief	Obtem o tamanho m�ximo da fila
				 *
				 * \return	Tamanho m�ximo de elementos que a fila suporta
				 */
                int MaxSize();
				
				/*!
				 * \brief	Soma de todos os elementos de duas fila
				 *
				 * \param	queue	Fila
				 *
				 * \return	Nova fila com a soma de ambas
				 */
                CQueue operator+(CQueue queue);
				
				/*!
				 * \brief	Soma de um float em todos os elementos da fila
				 *
				 * \param	item	Valor
				 *
				 * \return	Nova fila com a soma
				 */
                CQueue operator+(float item);

				/*!
				 * \brief	Soma todos os elementos da fila � fila atual
				 *
				 * \param	queue	Fila
				 *
				 * \return	Fila atual com os elementos somados
				 */
                CQueue& operator+=(CQueue queue);
				
				/*!
				 * \brief	Soma de um float em todos os elementos da fila
				 *
				 * \param	item	Valor
				 *
				 * \return	Fila atual com os elementos somados
				 */
                CQueue& operator+=(float item);

				/*!
				 * \brief	Obtem um elemento da fila
				 *
				 * \param	item	Posi��o da fila
				 *
				 * \return	Valor armazenado
				 */
                float operator[](int index);

				/*!
				 * \brief	Compara se duas filas s�o iguais
				 *
				 * \param	list Fila
				 *
				 * \return	True para iguais, False para diferentes
				 */
                bool operator==(CQueue queue);
				
				/*!
				 * \brief	Compara se duas filas s�o diferentes
				 *
				 * \param	list	Fila
				 *
				 * \return	True para diferentes, False para iguais
				 */
                bool operator!=(CQueue queue);

				/*!
				 * \brief	Insere um novo valor na fila
				 *
				 * \param	item	Valor
				 */
                void operator<<(float item);
				
				/*!
				 * \brief	Recupera um valor na fila
				 *
				 * \param	item	Valor float
				 */
                void operator>>(float& item);
				
				/*!
				 * \brief	Soma entre float e uma lista
				 *
				 * \param	item	Valor
				 * \param	queue	Lista
				 *
				 * \return	Nova fila somada
				 */
                friend CQueue operator+(float item, CQueue queue)
				{
					CQueue newQueue(queue.MaxSize());
					newQueue = queue + item;
					return newQueue;
				}

				/*!
				 * \brief	Imprime a fila
				 *
				 * \param	stream	Stream
				 * \param	queue	Queue
				 *
				 * \return	Impress�o dos elementos da fila
				 */
                friend ostream& operator<<(ostream& stream, CQueue queue)
				{
					int index = queue.GetBeginPosition();

					stream << "[";
					for (int i = 0; i < queue.Size(); i++)
					{
						stream << queue[(index + i) % queue.MaxSize()];

						if (i < queue.Size() - 1)
						{
							stream << ",";
						}
					}
					stream << "]" << endl;
					return stream;
				}
        };
    }
}


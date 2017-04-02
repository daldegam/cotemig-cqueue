namespace Cotemig
{
    namespace Queue
    {
		/*!
		 * \class	CQueue
		 *
		 * \brief	Classe de fila de números float com implementação de ponteiros
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
				 * \brief	Tamanho máximo da fila
				 */
                int m_iMaxSize;
				
				/*!
				 * \brief	Posição inicial da fila
				 */
                int m_iBegin;

				/*!
				 * \brief	Posição final da fila
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
				 * \brief	Obtem a posição atual a ser lida na fila
				 *
				 * \return	Valor atual da posição na fila
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
				 * \brief	Verifica se a fila está vazia
				 *
				 * \return	True para vazio, False para quando exitir elementos na lista
				 */
                bool IsEmpty();
				
				/*!
				 * \brief	Verifica se a fila está cheia
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
				 * \brief	Obtem o tamanho máximo da fila
				 *
				 * \return	Tamanho máximo de elementos que a fila suporta
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
				 * \brief	Soma todos os elementos da fila à fila atual
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
				 * \param	item	Posição da fila
				 *
				 * \return	Valor armazenado
				 */
                float operator[](int index);

				/*!
				 * \brief	Compara se duas filas são iguais
				 *
				 * \param	list Fila
				 *
				 * \return	True para iguais, False para diferentes
				 */
                bool operator==(CQueue queue);
				
				/*!
				 * \brief	Compara se duas filas são diferentes
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
				 * \return	Impressão dos elementos da fila
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


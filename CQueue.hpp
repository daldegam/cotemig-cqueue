namespace Cotemig
{
    namespace Queue
    {
        class CQueue
        {
            private:
                int m_bDebug;
                int m_iMaxSize;
                int m_iBegin;
                int m_iEnd;
                float * p_fItems;

            public:
                CQueue(int size);
                ~CQueue();

                void Insert(float item);
                float Remove();
                bool IsEmpty();
                bool IsFull();
                int Size();
                int MaxSize();
        };
    }
}
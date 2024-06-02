// ---- LIFECYCLE ---



// ---- GETTERS ----

template <typename T>
const T& Stack<T>::peek () const noexcept
{
    return arr[size - 1];
}

template <typename T>
bool Stack<T>::isEmpty () const noexcept
{
    return (size == 0);
}

template <typename T>
void Stack<T>::print (std::ostream& out) const noexcept
{
    for (size_t i = 0; i < size; i++)
        out << arr[i];
}

// ---- SETTERS ----

template <typename T>
void Stack<T>::push (const T& element)
{
    T* buffer = new T[size + 1];

    try
    {
        for (size_t i = 0; i < size; i++)
            buffer[i] = arr[i];
        
        buffer[size] = element;
    }
    catch (...)
    {
        delete[] buffer;
        throw;
    }

    delete[] arr;
    arr = buffer;
    size++;
}

template <typename T>
void Stack<T>::pop ()
{
    T* buffer = new T[size - 1];
    
    try
    {
        for (size_t i = 0; i < (size - 1); i++)
            buffer[i] = arr[i];
    }
    catch (...)
    {
        delete[] buffer;
        throw;
    }

    delete[] arr;
    arr = buffer;

    size--;
}


// ---- PRIVATE ----

template <typename T>
void Stack<T>::clear () noexcept
{
    delete[] arr;
    size = 0;
}
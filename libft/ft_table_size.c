int ft_table_size(char **table)
{
    int size;

    size = 0;
    while (table[size])
        size++;

    return (size);
}
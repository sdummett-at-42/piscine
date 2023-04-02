int	main()
{
	t_list	*lst;
	t_list	*lst2;
	t_list	*curr;
	int	*tab;
	int	*tab2;
	int	i;

	if (!(tab = malloc(sizeof(int) * 10)))
		return (0);
	if (!(tab2 = malloc(sizeof(int) * 10)))
		return (0);
	i = 0;
	while (i < 10)
	{
		*(tab + i) = i;
		ft_list_push_back(&lst, (tab + i));
		i++;
	}
	i = 0;
	while (i < 10)
	{
		*(tab2 + i) = i;
		ft_list_push_back(&lst2, (tab2 + i));
		i++;
	}
	printf("		>>>BEFORE MERGING && SORTING<<<\n");
	curr = lst;
	while (curr)
	{
		printf("lst->data %d  | %p\n", *(int *)curr->data, curr);
		curr = curr->next;
	}
	curr = lst2;
	while (curr)
	{
		printf("lst2->data %d | %p\n", *(int *)curr->data, curr);
		curr = curr->next;
	}
	ft_sorted_list_merge(&lst, lst2, &comp);

	printf("		>>>AFTER MERGING && SORTING<<<\n");
	curr = lst;
	while (curr)
	{
		printf("lst->data %d  | %p\n", *(int *)curr->data, curr);
		curr = curr->next;
	}
	curr = lst2;
	while (curr)
	{
		printf("lst2->data %d | %p\n", *(int *)curr->data, curr);
		curr = curr->next;
	}
	return (0);
}


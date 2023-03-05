/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsousa <thsousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:50:46 by thsousa           #+#    #+#             */
/*   Updated: 2022/05/24 11:35:48 by thsousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;

	if (lst && f)
	{
		new = ft_lstnew(f(lst->content));
		temp = new;
		while (lst->next)
		{
			lst = lst->next;
			temp->next = ft_lstnew(f(lst->content));
			if (!temp->next)
			{	
				ft_lstclear(&temp, del);
				return (NULL);
			}
			temp = temp->next;
		}	
		return (new);
	}
	return (NULL);
}

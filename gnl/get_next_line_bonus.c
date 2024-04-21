/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarustam < aarustam@student.42yerevan.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:05:15 by aarustam          #+#    #+#             */
/*   Updated: 2024/04/21 23:47:43 by aarustam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_to_line_reminder(int fd, char *line_reminder)
{
	char	*buff;
	int		read_bytes;

	buff = (char *)malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(line_reminder, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free(line_reminder);
			line_reminder = NULL;
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		line_reminder = ft_strjoin(line_reminder, buff);
	}
	free (buff);
	return (line_reminder);
}

char	*get_line_(char *line_reminder)
{
	int		i;
	char	*line;

	i = 0;
	if (!line_reminder || line_reminder[0] == '\0')
		return (NULL);
	while (line_reminder[i] && line_reminder[i] != '\n')
		i++;
	line = (char *)malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (line_reminder[i] && line_reminder[i] != '\n')
	{
		line[i] = line_reminder[i];
		i++;
	}
	if (line_reminder[i] == '\n')
	{
		line[i] = line_reminder[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*new_line_reminder(char *line_reminder)
{
	int		i;
	int		j;
	char	*new_line_reminder;

	i = 0;
	while (line_reminder[i] && line_reminder[i] != '\n')
		i++;
	if (!line_reminder[i])
	{
		free(line_reminder);
		return (NULL);
	}
	new_line_reminder = (char *)malloc(ft_strlen(line_reminder) - i + 1);
	if (!new_line_reminder)
		return (NULL);
	j = 0;
	i++;
	while (line_reminder[i])
		new_line_reminder[j++] = line_reminder[i++];
	new_line_reminder[j] = '\0';
	free (line_reminder);
	return (new_line_reminder);
}

char	*get_next_line(int fd)
{
	char	*line_reminder[OPEN_MAX];
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
	{
		return (NULL);
	}
	line_reminder[fd] = read_to_line_reminder(fd, line_reminder[fd]);
	if (!line_reminder[fd] || line_reminder[fd][0] == '\0')
	{
		free(line_reminder[fd]);
		line_reminder[fd] = NULL;
		return (NULL);
	}
	line = get_line_(line_reminder[fd]);
	line_reminder[fd] = new_line_reminder(line_reminder[fd]);
	return (line);
}

// // int	main(void)
// //  {
// //  	char	*line;
// //  	int		i;
// //  	int		fd1;
// //  	int		fd2;
 
// //  	fd1 = open("test1.txt", O_RDONLY);
// //  	fd2 = open("test2.txt", O_RDONLY);

// //  	i = 1;
// //  	while (i < 2)
// //  	{
// //  		line = get_next_line(fd1);
// //  		printf("line = %s", line);
// //  		free(line);
// //  		line = get_next_line(fd2);
// //  		printf("line = %s", line);
// //  		free(line);
// //  		i++;
// //  	}
	
// //  	system("leaks a.out");
// //  	close(fd1);
// //  	close(fd2);
 
// //  	return (0);
// // }
// int	main(void)
//  {
//  	char	*line;
//  	int		i;
//  	int		fd1;
//  	int		fd2;
 
//  	fd1 = open("test1.txt", O_RDONLY);
//  	fd2 = open("test2.txt", O_RDONLY);

//  	i = 1;
//  		line = get_next_line(fd1);
// 		printf("line = %s", line);
// 	free(line);
// 		line = get_next_line(fd2);
// 		printf("line = %s", line);
// 	free(line);
// 		line = get_next_line(fd1);
// 		printf("line = %s", line);
// 	free(line);
// 		line = get_next_line(fd2);
// 		printf("line = %s", line);
// 	free(line);


	
// 	char *temp;
// 			do
// 			{
// 				temp = get_next_line(fd1);
// 				// printf("line = %s", temp);
// 				free(temp);
// 			} while (temp != NULL);



			
// 		line = get_next_line(fd1);
// 		printf("line = %s", line);
// 	free(line);
// 	close(fd1);	
// 	fd1 = open("test1.txt", O_RDONLY);		
// 		line = get_next_line(fd2);
// 		printf("line = %s", line);
// 	free(line);
// 		line = get_next_line(fd2);
// 		printf("line = %s", line);
// 	free(line);
		
// 		line = get_next_line(fd1);
// 		printf("line = %s", line);
// 		free(line);
//  	//system("leaks a.out");
//  	close(fd1);
//  	close(fd2);
// 	 	return (0);
// }
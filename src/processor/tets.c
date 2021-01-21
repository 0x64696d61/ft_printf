{
	if ((flag->width - (int)ft_strlen(string)) >= 0)
		offset = flag->width - (int)ft_strlen(string);
	else
	{
		flag->minus = 1;
		offset = (flag->width + (int)ft_strlen(string)) * -1;
	}
	string = fill_line(string, offset, *flag);

}

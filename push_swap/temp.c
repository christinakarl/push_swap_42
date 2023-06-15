//under {NAME} in makefile
				@echo "$(COLOUR_VIO)      ___          ___          ___          ___              $(COLOUR_END)"
				@echo "$(COLOUR_VIO)     /\  \        /\  \        /\__\        /\  \             $(COLOUR_END)"
				@echo "$(COLOUR_VIO)    /::\  \      /::\  \      /::|  |      /::\  \            $(COLOUR_END)"
				@echo "$(COLOUR_VIO)   /:/\:\  \    /:/\:\  \    /:|:|  |     /:/\:\  \           $(COLOUR_END)"
				@echo "$(COLOUR_VIO)  /:/  \:\__\  /:/  \:\  \  /:/|:|  |__  /::\~\:\  \          $(COLOUR_END)"
				@echo "$(COLOUR_VIO) /:/__/ \:|__|/:/__/ \:\__\/:/ |:| /\__\/:/\:\ \:\__\         $(COLOUR_END)"
				@echo "$(COLOUR_VIO) \:\  \ /:/  /\:\  \ /:/  /\/__|:|/:/  /\:\~\:\ \/__/         $(COLOUR_END)"
				@echo "$(COLOUR_VIO)  \:\  /:/  /  \:\  /:/  /     |:/:/  /  \:\ \:\__\           $(COLOUR_END)"
				@echo "$(COLOUR_VIO)   \:\/:/  /    \:\/:/  /      |::/  /    \:\ \/__/           $(COLOUR_END)"
				@echo "$(COLOUR_VIO)    \::/  /      \::/  /       /:/  /      \:\__\             $(COLOUR_END)"
				@echo "$(COLOUR_VIO)     \/__/        \/__/        \/__/        \/__/$(COLOUR_END)"


//boucle in algo_more:
		// print_stack('a', *a);
		// print_stack('b', *b);
		// ft_printf("\n");

		// ft_printf("b's length: %d\n", (*b)->len);
		// if ((*b)->to)
		// 	ft_printf("b's target: %d cont: %d, index: %d, nr of moves necessary: %d\n", (*b)->to->cont, (*b)->cont, (*b)->index, (*b)->mov);

		// ft_printf("best option: %d\n", best_option);

//print in move_best_option
	// ft_printf("c->pos: %d & c->to->pos: %d\n", c->pos, c->to->pos);
	// ft_printf("b med: %d and b len: %d\n", (*b)->med, (*b)->len);
	// ft_printf("a med: %d and a len: %d\n", (*a)->med, (*a)->len);

//from move_best_option
	// if (c->pos <= (*b)->med && c->to->pos > (*a)->med)
	// {
	// 	rep_act2(b, rb, c->pos);
	// 	rep_act2(a, rra, ((*a)->len - c->to->pos));
	// 	ft_printf("first condition\n");
	// }
	// else if (c->pos > (*b)->med && c->to->pos <= (*a)->med)
	// {
	// 	rep_act2(b, rrb, ((*b)->len - c->pos));
	// 	rep_act2(a, ra, c->to->pos);
	// }

			// if (((*b)->len - c->pos) > ((*a)->len - c->to->pos))
		// 	turn = ((*b)->len - c->pos) - ((*a)->len - c->to->pos);
		// else if (((*b)->len - c->pos) < ((*a)->len - c->to->pos))
		// 	turn = ((*a)->len - c->to->pos) - ((*b)->len - c->pos);
		// else if (((*b)->len - c->pos) == ((*a)->len - c->to->pos))
		// 	turn = (*b)->len - c->pos;

			// if ((*a)->pos != 0 && (*b)->pos != 0)
	// 	set_lm(a, b);
return {
	{
		"nvim-telescope/telescope.nvim",
		tag = "0.1.4",
		depedencies = { "nvim-lua/plenary.nvim" },
		config = function()
			require("telescope").setup({
				defaults = {
					preview = {
						treesitter = false,
					},
				},
			})

			local builtin = require("telescope.builtin")
			vim.keymap.set("n", "<leader>ff", builtin.find_files, { desc = "Files Find" })
			vim.keymap.set("n", "<leader>fg", builtin.live_grep, { desc = "Files Grep" })
			vim.keymap.set("n", "<leader>ft", builtin.buffers, { desc = "Buffers" })

			vim.keymap.set("n", "<leader>d", "<cmd>Telescope lsp_definitions<CR>", { desc = "goto Definition" })
			vim.keymap.set("n", "<leader>gr", "<cmd>Telescope lsp_references<CR>", { desc = "Goto References" })
			vim.keymap.set("n", "<leader>E", "<cmd>Telescope diagnostics<CR>", { desc = "show diagnostics (Errors)" })
			vim.keymap.set(
				"n",
				"<leader>gi",
				"<cmd>Telescope lsp_implementations<CR>",
				{ desc = "Goto Implementations" }
			)
		end,
	},
	{
		"nvim-telescope/telescope-file-browser.nvim",
		dependencies = { "nvim-telescope/telescope.nvim", "nvim-lua/plenary.nvim" },
		config = function()
			require("telescope").load_extension("file_browser")
			local fb = require("telescope").extensions.file_browser
			vim.keymap.set("n", "<leader>fb", fb.file_browser, { desc = "File Browser" })
		end,
	},
	{
		"nvim-telescope/telescope-ui-select.nvim",
		config = function()
			require("telescope").setup({
				extensions = {
					["ui-select"] = {
						require("telescope.themes").get_dropdown({}),
					},
				},
			})
			require("telescope").load_extension("ui-select")
		end,
	},
}

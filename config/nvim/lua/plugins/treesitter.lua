return {
	"nvim-treesitter/nvim-treesitter",
	dependencies = {
		"nvim-treesitter/nvim-treesitter-textobjects",
	},
	build = ":TSUpdate",
	config = function()
		---@diagnostic disable-next-line: missing-fields
		require("nvim-treesitter.configs").setup({
			auto_install = true,
			ensure_installed = { "lua", "python", "cpp", "latex", "typescript" },
			highlight = {
				enable = true,
				additional_vim_regex_highlighting = false
			},
			indent = {
				enable = true,
			},
			textobjects = {
				select = {
					enable = true,
					lookahead = true,

					keymaps = {
						["af"] = "@function.outer",
						["if"] = "@function.inner",
						["ai"] = "@conditional.outer",
						["ii"] = "@conditional.inner",
					},
				},
				move = {
					enable = true,
					set_jumps = true, -- whether to set jumps in the jumplist
					goto_next_start = {
						["<leader>na"] = "@parameter.inner",
						["<leader>nf"] = "@function.outer", -- next function
						["<leader>nl"] = "@loop.inner",
						["<leader>ni"] = "@conditional.inner",
						["<leader>nc"] = "@class.outer",
					},
					goto_previous_start = {
						["<leader>Na"] = "@parameter.inner",
						["<leader>wf"] = "@function.outer", -- which function
						["<leader>wl"] = "@loop.inner",
						["<leader>wi"] = "@conditional.inner",
						["<leader>wc"] = "@class.outer",
					},
				},
			},
		})
	end,
}

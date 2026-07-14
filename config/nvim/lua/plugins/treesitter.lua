return {
	"nvim-treesitter/nvim-treesitter",
	branch = "main",
	lazy = false,
	build = ":TSUpdate",
	dependencies = {
		{ "nvim-treesitter/nvim-treesitter-textobjects", branch = "main" },
	},
	config = function()
		local ensure_installed = { "lua", "python", "cpp", "latex", "typescript" }

		require("nvim-treesitter").install(ensure_installed)

		require("nvim-treesitter-textobjects").setup({
			select = {
				lookahead = true,
			},
			move = {
				set_jumps = true,
			},
		})

		vim.api.nvim_create_autocmd("FileType", {
			callback = function(args)
				local ok = pcall(vim.treesitter.start, args.buf)
				if ok then
					vim.bo[args.buf].indentexpr = "v:lua.require'nvim-treesitter'.indentexpr()"
				end
			end,
		})

		local select = require("nvim-treesitter-textobjects.select")
		vim.keymap.set({ "x", "o" }, "af", function()
			select.select_textobject("@function.outer", "textobjects")
		end)
		vim.keymap.set({ "x", "o" }, "if", function()
			select.select_textobject("@function.inner", "textobjects")
		end)
		vim.keymap.set({ "x", "o" }, "ai", function()
			select.select_textobject("@conditional.outer", "textobjects")
		end)
		vim.keymap.set({ "x", "o" }, "ii", function()
			select.select_textobject("@conditional.inner", "textobjects")
		end)

		local move = require("nvim-treesitter-textobjects.move")
		vim.keymap.set({ "n", "x", "o" }, "<leader>na", function()
			move.goto_next_start("@parameter.inner", "textobjects")
		end)
		vim.keymap.set({ "n", "x", "o" }, "<leader>nf", function()
			move.goto_next_start("@function.outer", "textobjects")
		end)
		vim.keymap.set({ "n", "x", "o" }, "<leader>nl", function()
			move.goto_next_start("@loop.inner", "textobjects")
		end)
		vim.keymap.set({ "n", "x", "o" }, "<leader>ni", function()
			move.goto_next_start("@conditional.inner", "textobjects")
		end)
		vim.keymap.set({ "n", "x", "o" }, "<leader>nc", function()
			move.goto_next_start("@class.outer", "textobjects")
		end)

		vim.keymap.set({ "n", "x", "o" }, "<leader>Na", function()
			move.goto_previous_start("@parameter.inner", "textobjects")
		end)
		vim.keymap.set({ "n", "x", "o" }, "<leader>wf", function()
			move.goto_previous_start("@function.outer", "textobjects")
		end)
		vim.keymap.set({ "n", "x", "o" }, "<leader>wl", function()
			move.goto_previous_start("@loop.inner", "textobjects")
		end)
		vim.keymap.set({ "n", "x", "o" }, "<leader>wi", function()
			move.goto_previous_start("@conditional.inner", "textobjects")
		end)
		vim.keymap.set({ "n", "x", "o" }, "<leader>wc", function()
			move.goto_previous_start("@class.outer", "textobjects")
		end)
	end,
}

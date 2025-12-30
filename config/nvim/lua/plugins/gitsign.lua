return {
	"lewis6991/gitsigns.nvim",
	config = function()
		require("gitsigns").setup({
			on_attach = function(bufnr)
				local gitsigns = require("gitsigns")

				local function map(mode, l, r, opts)
					opts = opts or {}
					opts.buffer = bufnr
					vim.keymap.set(mode, l, r, opts)
				end

				map("n", "<leader>kr", function()
					gitsigns.reset_hunk()
				end)

				map("n", "<leader>ks", function()
					gitsigns.stage_hunk()
				end)

				map("n", "<leader>kb", function()
					gitsigns.blame_line({ full = true })
				end)

				map("n", "<leader>kB", gitsigns.toggle_current_line_blame)

				map("n", "<leader>ng", function()
					gitsigns.nav_hunk("next")
				end)

				map("n", "<leader>Ng", function()
					gitsigns.nav_hunk("prev")
				end)
			end,
		})
	end,
}

return {
	"catppuccin/nvim",
	name = "catppuccin",
	priority = 1000,
	config = function()
		require("catppuccin").setup({
			flavour = "mocha",
			transparent_background = true,
			color_overrides = {
        all = {
          rosewater = "#dfd0dc",
          flamingo = "#f5a2c7",

          maroon = "#fd971f", -- maroon is just orange
          peach = "#fd971f",

          lavender = "#ae81ff",

          -- there is one red
          pink = "#f92672",
          mauve = "#f92672",
          red = "#f92672",

          green = "#a6e22e",
          yellow = "#e6db74",

          -- there is one blue
          teal = "#66d9ef",
          sky = "#66d9ef",
          sapphire = "#66d9ef",
          blue = "#66d9ef",

          text = "#f8f8f0",
          subtext1 = "#babab0",
          subtext0 = "#a6a6a0",
          overlay2 = "#939390",
          overlay1 = "#7f7f76",
          overlay0 = "#6c6c60",
          surface2 = "#585850",
          surface1 = "#454550",
          surface0 = "#31313a",
          base = "#1e1e24",
          mantle = "#18181f",
          crust = "#111111"
        }
      },
      highlight_overrides = {
        all = function(colors)
          return {
            String = { fg = colors.yellow },
            DiffAdd = { fg = colors.green },
            DiffChange = { fg = colors.yellow },
            DiffDelete = { fg = colors.red },
            LineNr = { fg = colors.rosewater }
          }
        end,
      },
			integrations = {
				cmp = true,
				gitsigns = true,
			},
		})

		vim.cmd.colorscheme("catppuccin")
	end,
}

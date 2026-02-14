local make_snippets = function(ls)
	local s = ls.snippet
	local t = ls.text_node
	local i = ls.insert_node
	local f = ls.function_node

  -- template for internal logger
	-- ls.add_snippets("cpp", {
	-- 	s({trig="LogNow", snippetType="autosnippet"}, {
	-- 		t("std::cout << "), i(1), t(" << std::endl;"),
	-- 	}),
	-- })

	ls.add_snippets("all", {
		s("pwd", {
			f(function()
				return vim.fn.getcwd()
			end),
		}),
	})
end

return {
	"L3MON4D3/LuaSnip",
	version = "v2.*",
	build = "make install_jsregexp",
	config = function()
		local ls = require("luasnip")

    ls.config.set_config({ enable_autosnippets = true, })
		vim.keymap.set("i", "<C-x>", function()
			if ls.expandable() then
				ls.expand()
			end
		end, { silent = true })

		make_snippets(ls)
	end,
}

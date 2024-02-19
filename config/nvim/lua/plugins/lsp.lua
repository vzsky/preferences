local servers = {
  lua_ls = {},
  clangd = {},
  -- Create ~/.clangd solves library seeking issues.
  eslint = {},
  hls = {},
  tsserver = {},
  texlab = {},
  pyright = {},
  marksman = {},
}

return {
  'neovim/nvim-lspconfig',
  dependencies = {
    'hrsh7th/cmp-nvim-lsp',
    'williamboman/mason.nvim',
    'williamboman/mason-lspconfig.nvim',
    { 'j-hui/fidget.nvim', tag = "legacy", opts = {} },
    'folke/neodev.nvim',
  },
  config = function()
    require("neodev").setup({})
    require("mason").setup()

    local mason_lspconfig = require("mason-lspconfig")

    mason_lspconfig.setup({
      ensure_installed = vim.tbl_keys(servers)
    })

    local capabilities = vim.lsp.protocol.make_client_capabilities()
    capabilities = require('cmp_nvim_lsp').default_capabilities(capabilities)

    mason_lspconfig.setup_handlers {
      function(server_name)
        require('lspconfig')[server_name].setup {
          capabilities = capabilities,
          settings = servers[server_name],
        }
      end,
    }

    vim.keymap.set('n', '<leader>e', vim.diagnostic.open_float)
    vim.keymap.set('n', '<leader>h', vim.lsp.buf.hover)
    vim.keymap.set('n', '<leader>d', vim.lsp.buf.definition)
    vim.keymap.set('n', '<leader>t', vim.lsp.buf.type_definition)
    vim.keymap.set('n', '<leader>ca', vim.lsp.buf.code_action)
  end
}

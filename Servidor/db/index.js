const { Pool } = require("pg");
const config   = require("../config/db.config.js")

const pool = new Pool(config);

module.exports = { query: (text, params) => pool.query(text, params) };

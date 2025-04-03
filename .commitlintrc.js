module.exports = {
    extends: ['@commitlint/config-conventional'],
    rules: {
        "scope-enum": [2, 'always', [
            "docker",
            "zephyr"
        ]],
        "scope-empty": [2, 'never']     // disallow empty scopes
    },
};

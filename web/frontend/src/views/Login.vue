<template>
    <div id="login">
        <h1>Login</h1>
        <div class="form-inputs">
            <n-input v-model:value="value" type="text" placeholder="Email" />
        </div>
        <div class="form-inputs">
            <n-input
                type="password"
                show-password-on="mousedown"
                placeholder="Password"
                :maxlength="64"
            />
        </div>
        <n-button type="info" v-on:click="login()">Login</n-button>
    </div>
</template>

<script>
    export default {
        name: 'MyLogin',
        data() {
            return {
                input: {
                    username: "",
                    password: ""
                }
            }
        },
        methods: {
            login() {
                if(this.input.username != "" && this.input.password != "") {
                    // This should actually be an api call not a check against this.$parent.mockAccount
                    if(this.input.username == this.$parent.mockAccount.username && this.input.password == this.$parent.mockAccount.password) {
                        this.$emit("authenticated", true);
                        this.$router.replace({ name: "Secure" });
                    } else {
                        console.log("The username and / or password is incorrect");
                    }
                } else {
                    console.log("A username and password must be present");
                }
            }
        }
    }
</script>

<style>

#login .form-inputs {
    padding-bottom: 10px;
}

#login .form-inputs label {
    padding-right: 10px;
}

</style>
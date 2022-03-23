<template>
  <nav>
    <router-link to="/">Home</router-link> |
      <router-link v-if="authenticated" to="/secure">Secure</router-link>
      <router-link v-if="authenticated" to="/login" v-on:click.enter="logout()" replace>Logout</router-link>
      <router-link v-else to="/login">Login</router-link>
  </nav>
  <router-view/>
</template>

<script>
    export default {
        name: 'App',
        data() {
            return {
                authenticated: false,
                // this is only for testing purposes no actual app will have this
                // an api call will validate user credentials
                mockAccount: {
                    username: "testi",
                    password: "ss",
                }
            }
        },
        methods: {
            setAuthenticated(status) {
                this.authenticated = status;
            },
            logout() {
                this.authenticated = false;
            }
        }
    }
</script>

<style>
#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #303941;
}

nav {
  padding: 30px;
}

nav a {
  font-weight: bold;
  color: #000000;
}

nav a.router-link-exact-active {
  color: #049aff;
}
</style>

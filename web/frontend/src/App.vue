
<template>
  <v-app id="app">
    <v-main>    
      <v-container class="py-8 px-6" fluid>
        <router-view></router-view>
      </v-container>
    </v-main>
  </v-app>
</template>

<script>
    import Sidebar from "./components/Sidebar";
    import Topbar from "./components/Topbar";
    export default {  
        name: "App",
          components: { Topbar, Sidebar },
          data: () => ({
            drawer: null,
          }),
        }      
</script>

<style>
    body {
        background-color: #202227;
    }
    h1 {
        padding: 0;
        margin-top: 0;
    }
    #app {
        background-color: #202227;
    }

    
</style>
<template>
   <div>
    <Sidebar :drawer="drawer" />
    <Topbar @drawerEvent="drawer = !drawer" />
   </div>
</template>

<script>
    import Sidebar from "../components/Sidebar";
    import Topbar from "../components/Topbar";
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
        background-color: #000000;
    }
        
</style>
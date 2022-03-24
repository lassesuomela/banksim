<template>
    <div id="app">
        <div id="nav">
            
            
        </div>
        <router-view @authenticated="setAuthenticated" />
    </div>
</template>

<script>
    
</script>

<style>
    body {
        background-color: #F0F0F0;
        
    }
    h1 {
        padding: 0;
        margin-top: 0;
    }
    #app {
        width: 1024px;
        margin: auto;

    }
</style>
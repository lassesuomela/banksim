
<template>
        <div>
        <app-sidebar/>
        <app-Acctable/>
        <br>
        <app-Pie/>
        </div>  
             
</template>

<script>
    export default {
        name: "Dashboard",
        data() {
            return {
                fname: "",
                activityLog: [
                    {title: 'acc 1', text: 'montako', amount: 5000, icon: 'mdi-account', color: 'cyan lighten-3'},
                    {title: 'acc 2', text: 'id', amount: 3433, icon: 'mdi-account-group-outline', color: 'green darken-2'},
                    {title: 'acc 3', text: 'joku', amount: 3433, icon: 'mdi-account-group-outline', color: 'blue-grey darken-1'},

                ],
            }
        },       
    }
    
</script>

<style scoped>
    .overlap-icon {
        position: absolute;
        top: -33px;
        text-align: center;
        padding-top: 12px;
    }
    
    
</style>
